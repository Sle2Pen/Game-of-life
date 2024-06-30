#include "renderer.h"

void swap_display_buffer(void* current_display_buffer, void* future_display_buffer)
{
  void* tmp=NULL;
  tmp=*(TBufferPointer**)current_display_buffer;
  *(TBufferPointer**)current_display_buffer=*(TBufferPointer**)future_display_buffer;
  *(TBufferPointer**)future_display_buffer=tmp;
}

void render_display_buffer(void* rendering_buffer, int rows, int columns)
{
  TBufferPointer* buffer_pointer=NULL;
  buffer_pointer=(TBufferPointer*) rendering_buffer;

  for(int y=0;y<rows;y++){
    for(int x=0;x<columns;x++)
      putchar(buffer_pointer[y][x] ? 'O':' ');
    putchar('\n');
  }
}

