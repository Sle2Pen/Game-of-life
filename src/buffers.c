#include "buffers.h"

void* create_buffer(int rows,int columns)
{ 
  TBufferPointer* buffer_pointer=NULL;
  size_t buffer_size=0;

  buffer_size=rows*sizeof(TBufferPointer);
  buffer_pointer=(TBufferPointer*) malloc(buffer_size);

  for(int i=0; i<rows; i++)
    buffer_pointer[i]=(TBufferPointer) malloc(columns*sizeof(int));

  return buffer_pointer;
}

void initialize_buffer(void* buffer, int rows, int columns)
{
  TBufferPointer* buffer_pointer=NULL;
  buffer_pointer=(TBufferPointer*) buffer;

  for(int y=0; y<rows;y++)
    for(int x=0; x<columns; x++)buffer_pointer[y][x]=rand() % 2;
      //buffer_pointer[y][x]=0; //don't forget uncomment this
}

void release_buffer(void* releasing_buffer, int rows)
{
  TBufferPointer* buffer_pointer=NULL;
  buffer_pointer=(TBufferPointer*) releasing_buffer;

  for(int y=0;y<rows;y++)
    free(buffer_pointer[y]);

  free(buffer_pointer);
}

