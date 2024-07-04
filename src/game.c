#include "game.h"

int game_loop()
{
  int rows = 25,columns = 80;
  int return_val=0,menu_loading_result=0;
  TBufferPointer *current_render_buffer=NULL, *future_render_buffer=NULL, *menu_render_buffer=NULL;
  char key='1';
  char menu_path[]="game.menu";
  int pause=1000000;
  //int counter=0;
  
  int error_flag=0;
  
  current_render_buffer=(TBufferPointer*)create_buffer(rows,columns);
  if(current_render_buffer==NULL) 
  {
    printf("Houston, we got a problem...with first buffer\n");
    error_flag++;
  }
  else
    initialize_buffer(current_render_buffer, rows, columns);
  
  future_render_buffer=(TBufferPointer*)create_buffer(rows,columns);
  if(future_render_buffer==NULL)
  {
    printf("Houston, we got a problem...with second buffer\n");
    error_flag++;
  }
  else
    initialize_buffer(future_render_buffer, rows, columns);

  
  menu_render_buffer=(TBufferPointer*) create_buffer(rows,MENU_WIDTH);
  if(menu_render_buffer==NULL)
  {
    printf("Houston, we got a problem...with menu buffer\n");
    error_flag++;
  }
  else
    initialize_buffer(menu_render_buffer, rows, MENU_WIDTH);

  if(error_flag==0)
  {
    fill_buffer(current_render_buffer, rows, columns);

    freopen("/dev/tty","r",stdin);

    menu_loading_result=load_file(menu_render_buffer,rows,MENU_WIDTH,menu_path);

    set_keypress(); 
  
    while(key!='q' && key!='Q')
    {

      system("clear");
      //printf("\n\nrender---------------------%d\n\n",counter++);
    
      render_display(current_render_buffer,rows,columns,menu_render_buffer);

      calculate_rendering_state(current_render_buffer,future_render_buffer,rows,columns);

      swap_display_buffer(&current_render_buffer, &future_render_buffer);

      set_pause_in_microseconds(pause);

      return_val=wait_keypress();
      if(return_val)
      key=getchar();

      switch(key)
      {
        case '+':
          if(pause>0)
            pause-=50000;
          else
            pause=0;
          key='1';
          break;
        case '-':
            pause+=50000;
          key='1';
          break;
      }
    }

    reset_color();
  
    reset_keypress();
  }
  release_buffer(current_render_buffer,rows);
  release_buffer(future_render_buffer,rows);
  release_buffer(menu_render_buffer,rows);
  
  system("clear");
  
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
