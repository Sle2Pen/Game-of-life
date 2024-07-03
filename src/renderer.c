#include "renderer.h"

void swap_display_buffer(void* current_display_buffer, void* future_display_buffer)
{
  void* tmp=NULL;
  tmp=*(TBufferPointer**)current_display_buffer;
  *(TBufferPointer**)current_display_buffer=*(TBufferPointer**)future_display_buffer;
  *(TBufferPointer**)future_display_buffer=tmp;
}

void render_display(void* rendering_buffer, int rows, int columns, void* menu_buffer)
{
  TBufferPointer* buffer_pointer=NULL;
  TBufferPointer* menu_buffer_pointer=NULL;
  
  buffer_pointer=(TBufferPointer*) rendering_buffer;
  menu_buffer_pointer=(TBufferPointer*) menu_buffer;

  int screen_width=0,screen_height=0;
  screen_width=columns+3*SCREEN_BORDER_WIDTH+MENU_WIDTH;
  screen_height=rows+2*SCREEN_BORDER_HEIGHT;
  
  int start_y=0,end_y=0;
  start_y = SCREEN_BORDER_HEIGHT;
  end_y = rows + SCREEN_BORDER_HEIGHT;

  int field_start_x=0,field_end_x=0;
  field_start_x = SCREEN_BORDER_WIDTH;
  field_end_x=columns+SCREEN_BORDER_WIDTH;

  int menu_start_x=0,menu_end_x=0;
  menu_start_x =screen_width-MENU_WIDTH-SCREEN_BORDER_WIDTH;
  menu_end_x=screen_width-SCREEN_BORDER_WIDTH;

  int screen_buffer[screen_height][screen_width]={};
  build_screen_buffer(buffer_pointer,screen_height,screen_width,screen_buffer);

  fill_screen_buffer(menu_buffer_pointer,screen_height,screen_width,screen_buffer, start_y, end_y, menu_start_x, menu_end_x);

  fill_screen_buffer(buffer_pointer,screen_height,screen_width,screen_buffer, start_y, end_y, field_start_x, field_end_x);

  int current_value=0;

  for(int y=0;y<screen_height;y++)
  {
    for(int x=0;x<screen_width;x++)
    {
      current_value=screen_buffer[y][x];

      switch(current_value)
      {
        case 0:
          set_display_attrib(SCREEN_FIELDS_BACKGROUND);
          putchar(' ');
          break;
        case 1:
          set_display_attrib(LIFE_CELL_BACKGROUND);
          putchar(' ');
          break;
        case 2:
          set_display_attrib(SCREEN_BACKGROUND);
          putchar(' ');
          break;
        default:
          set_display_attrib(SCREEN_FOREGROUND);
          putchar((char)current_value);
          break;
      }
    }
      reset_color();
      putchar('\n');
  }
}

void build_screen_buffer(TBufferPointer* screen_info_pointer,int screen_height,int screen_width,int screen_buffer[][screen_width])
{
  int left_screen_border=SCREEN_BORDER_WIDTH,
      menu_border_start=screen_width-2*SCREEN_BORDER_WIDTH;

  for(int y=0;y<screen_height;y++)
    for(int x=0;x<screen_width;x++)
        screen_buffer[y][x]=SCREEN_BORDER;
}
  
void fill_screen_buffer(TBufferPointer* info_buffer_pointer, int screen_height, int screen_width, int screen_buffer[][screen_width], int start_y, int end_y, int start_x, int end_x)
{
  for(int y=start_y;y<end_y;y++)
    for(int x=start_x;x<end_x;x++)
      screen_buffer[y][x]=info_buffer_pointer[y-start_y][x-start_x];
}
