#include "game.h"

int game_loop()
{
  int rows = 25,columns = 80;
  TBufferPointer current_render_buffer=NULL, preview_render_buffer=NULL;
  
  preview_render_buffer=create_buffer(rows,columns);
  initialize_buffer(preview_render_buffer, rows, columns);

  current_render_buffer=create_buffer(rows,columns);
  initialize_buffer(current_render_buffer, rows, columns);
  
  printf("\nfirst pointer : %p\nsecond pointer :%p\n",preview_render_buffer,current_render_buffer);
  
  render_display_buffer(current_render_buffer,rows,columns);

  release_buffer(current_render_buffer,rows);
  release_buffer(preview_render_buffer,rows);
  return 0;
}

void* create_buffer(int rows,int columns)
{ 
  TBufferPointer buffer_pointer=NULL;
  size_t buffer_size=0;

  buffer_size=rows*sizeof(int*);
  buffer_pointer=(TBufferPointer) malloc(buffer_size);

  for(int i=0; i<rows; i++)
    buffer_pointer[i]=(int*) malloc(columns*sizeof(int));

  return buffer_pointer;
}

void release_buffer(void* releasing_buffer, int rows)
{
  TBufferPointer buffer_pointer=NULL;
  buffer_pointer=(TBufferPointer) releasing_buffer;

  for(int i=0;i<rows;i++)
    free(buffer_pointer[i]);

  free(buffer_pointer);
}

void initialize_buffer(void* buffer, int rows, int columns)
{
  TBufferPointer buffer_pointer=NULL;
  buffer_pointer=(TBufferPointer) buffer;

  for(int i=0; i<rows;i++)
    for(int j=0; j<columns; j++)
      buffer_pointer[i][j]=0;
}

void swap_display_buffer()
{

}

void render_display_buffer(void* rendering_buffer, int rows, int columns)
{
  TBufferPointer buffer_pointer=NULL;
  buffer_pointer=(TBufferPointer) rendering_buffer;

  for(int i=0;i<rows;i++){
    for(int j=0;j<columns;j++)
      putchar(buffer_pointer[i][j]);
    putchar('\n');
  }
}

void calculate_rendering_state(void* preview_rendered_buffer,void* current_buffer_for_rendering)
{

}
