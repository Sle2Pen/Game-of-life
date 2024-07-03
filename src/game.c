#include "game.h"

int game_loop()
{
  int rows = 25,columns = 80;
  int return_val=0;
  TBufferPointer *current_render_buffer=NULL, *future_render_buffer=NULL;
  char key='1';
  int counter=0;
  
  current_render_buffer=(TBufferPointer*)create_buffer(rows,columns);
  initialize_buffer(current_render_buffer, rows, columns);
  
  future_render_buffer=(TBufferPointer*)create_buffer(rows,columns);
  initialize_buffer(future_render_buffer, rows, columns);

  fill_buffer(current_render_buffer, rows, columns);
  
  freopen("/dev/tty","r",stdin);
  set_keypress(); 
  
  while(key!='q' && key!='Q')
  {

    printf("\n\nrender---------------------%d\n\n",counter++);
    
    render_display_buffer(current_render_buffer,rows,columns);

    calculate_rendering_state(current_render_buffer,future_render_buffer,rows,columns);

    swap_display_buffer(&current_render_buffer, &future_render_buffer);
    set_pause_in_microseconds(100000);

    return_val=wait_keypress();
    if(return_val)
    key=getchar();
  }

  reset_color();
  
  reset_keypress();
  
  release_buffer(current_render_buffer,rows);
  release_buffer(future_render_buffer,rows);
  
  return 0;
}

void calculate_rendering_state(void* current_rendered_buffer,void* future_buffer_for_rendering, int rows, int columns)
{
  int neighbors_count=0;
  int height=0,width=0;

  TBufferPointer* current_pointer=NULL;
  TBufferPointer* future_pointer=NULL;

  height=rows;
  width=columns;

  current_pointer=(TBufferPointer*)current_rendered_buffer;
  future_pointer=(TBufferPointer*)future_buffer_for_rendering;

  for(int y=0; y<rows; y++)
   for(int x=0;x<columns; x++)
    {
      neighbors_count=0;

      for(int yn=-1;yn<2;yn++)
        for(int xn=-1;xn<2;xn++)
          if(yn!=0 || xn!=0)
            neighbors_count+=current_pointer[(height+(y-yn))%height][(width+(x-xn))%width];

      if(neighbors_count==3 && current_pointer[y][x]==0)future_pointer[y][x]=1;
      else if(neighbors_count<2 || neighbors_count>3) future_pointer[y][x]=0;
       else future_pointer[y][x]=current_pointer[y][x];
    }
  
}
