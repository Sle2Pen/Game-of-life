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
    for(int x=0; x<columns; x++)
      buffer_pointer[y][x]=0; 
}

int fill_buffer(void* buffer, int rows, int columns)
{
  TBufferPointer* buffer_pointer=NULL;
  buffer_pointer=(TBufferPointer*) buffer;
  
  char input_str[256]={};
  int return_result=0;

  for(int y=0;y<rows;y++){
    scanf("%s",input_str);
    printf("%s\n",input_str);

        for(int x=0;x<columns;x++)
          if(input_str[x]=='0')
            buffer_pointer[y][x]=0;
          else if(input_str[x]=='1')
            buffer_pointer[y][x]=1;
}


  return return_result;
}

void release_buffer(void* releasing_buffer, int rows)
{
  TBufferPointer* buffer_pointer=NULL;
  buffer_pointer=(TBufferPointer*) releasing_buffer;

  for(int y=0;y<rows;y++)
    free(buffer_pointer[y]);

  free(buffer_pointer);
}

