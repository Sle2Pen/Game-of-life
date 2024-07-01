#include "terminal_settings.h"

void set_keypress(void)
{
  struct termios new_settings;

  tcgetattr(0,&stored_settings);
  new_settings=stored_settings;

  //disable canonical mode
  new_settings.c_lflag &=(~ICANON);
  new_settings.c_cc[VTIME]=0;
  new_settings.c_cc[VMIN]=1;

  tcsetattr(0,TCSANOW,&new_settings);
  //??return;
}

void reset_keypress(void)
{
  tcsetattr(0,TCSANOW,&stored_settings);
  //??return;
}

int wait_keypress()
{
  fd_set return_file_descriptors;
  struct timeval time_value;
  int return_value=0;

  FD_ZERO(&return_file_descriptors);
  FD_SET(0,&return_file_descriptors);

  time_value.tv_sec=0;
  time_value.tv_usec=0;

  return_value=select(2,&return_file_descriptors,NULL,NULL,&time_value);

  return return_value;
}

void set_pause_in_microseconds(int microseconds)
{
  useconds_t usec=0;

  usec=(useconds_t) microseconds;

  usleep(usec);
}


