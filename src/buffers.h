#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int* TBufferPointer; 

void* create_buffer(int rows,int columns);
void initialize_buffer(void* buffer, int rows, int columns);
void release_buffer(void* releasing_buffer, int rows);
