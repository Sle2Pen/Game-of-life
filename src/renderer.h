#include "buffers.h"


#define ESC "\033"

#define set_display_attrib(color) printf(ESC "[%dm",color)
#define set_display_attrib_background(color) printf(ESC "[%sm",color)
#define reset_color() printf(ESC "[0m")

#define WHITE 47
#define BLUE 44
//#define SCREEN_BACKGROUND 90
//foreground ansi colors: \033[38;2;<r>;<g>;<b>m
//background ansi colors: \033[48;2;<r>;<g>;<b>m
#define SCREEN_BACKGROUND "48;2;195;195;195"

#define SCREEN_BORDER_HEIGHT 1
#define SCREEN_BORDER_WIDTH 2
//FOR NOW IS MACROS
#define MENU_WIDTH 30

#define SCREEN_BORDER 2

void swap_display_buffer(void* current_display_buffer, void* future_display_buffer);

void render_display_buffer(void* rendering_buffer, int rows, int columns);

void build_screen_buffer(TBufferPointer* screen_info_pointer,int screen_height,int screen_width,int screen_buffer[][screen_width]);

void fill_screen_buffer(TBufferPointer* info_buffer_pointer, int screen_height, int screen_width, int screen_buffer[][screen_width], int start_y, int end_y, int start_x, int end_x);

