
#include"header_file.h"

int main(int argn,char *argc[])
{	
 if(argn!=4)
 {
  printf("Error:Invalid Arguments\n");
  return 0;
 }

 if((strcmp(argc[1],"-P"))==0)
 {
   if(pack(argc[2],argc[3]))
   {
     printf("Packing done successfully\n");
   }
 }
 else if((strcmp(argc[1],"-U"))==0)
 {
   if(unpack(argc[2],argc[3]))
   {
    printf("Unpacking done succesfully\n");
   }
}
 else
  {
   printf("Error:Invalid arguments\n");
  }
return 0;
} 

