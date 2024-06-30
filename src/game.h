#include <stdio.h>
#include <stdlib.h>

typedef int** TBufferPointer; 

int game_loop();
void* create_buffer(int rows,int columns);
void initialize_buffer(void* buffer, int rows, int columns);
void release_buffer(void* releasing_buffer, int rows);
void swap_display_buffer();
void render_display_buffer(void* rendering_buffer, int rows, int columns);
void calculate_rendering_state(void* preview_rendered_buffer,void* current_buffer_for_rendering);
