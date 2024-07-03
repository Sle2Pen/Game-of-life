#include "file_loader.h"

int load_file(TBufferPointer* returning_buffer,int rows,int columns,char* file_path)
{
  int result=0;
  int cycle_key=1;
  FILE *opening_file_pointer=NULL;
  char* string_result=NULL;
  char string_buffer[columns+2]={};//for '\0' and '\n'

  opening_file_pointer=fopen(file_path,"r");

  if(opening_file_pointer==NULL) result=1;
  else
  {
    for(int y=0;y<rows && cycle_key!=0;y++){
      string_result=fgets(string_buffer,sizeof(string_buffer),opening_file_pointer);
      if(string_result!=NULL && ferror(opening_file_pointer)!=1)
      { 
        for(int x=0;x<columns;x++)
          if(string_result[x]=='0')
            returning_buffer[y][x]=0;
          else
            returning_buffer[y][x]=(int)string_result[x];
      }
      else 
      {
        cycle_key=0;
        result++;
      }
    }
    fclose(opening_file_pointer);
  }
  return result;
}
