#include"header_file.h"

int unpack(char fname[50],char fdname[50])
{
 int fdd=open(fname,O_RDONLY);
 if(fdd==-1)
 {
  printf("Error:Unable to open %s file\n",fname);
  return 0;
 }

 char namearr[100];
 char pathstr[120];

 sprintf(pathstr,"%s",fdname);

 int previous_mask= umask(0);

 mkdir(pathstr, 0x777);

 sprintf(pathstr,"%s/",fdname);

 char folder_path[50];

 sprintf(folder_path, "%s", pathstr);

 int fd;
 char nums[30];
 int i;
 char * buf;
 
 while(read(fdd,namearr,100))
 {

	  sprintf(pathstr,"%s%s",pathstr,namearr);

	  fd=creat(pathstr,0x777);

	  read(fdd,nums,30);

	  i=atoi(nums);

	  buf=(char *)malloc(i);

	  read(fdd,buf,i);

	  write(fd,buf,i);

	  close(fd);

	  free(buf);

	  sprintf(pathstr,"%s",folder_path);
 }

  umask(previous_mask);
return 1;
}////end of unpack function
