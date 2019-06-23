#include"header_file.h"

int pack(char fdname[50],char fname[50])
{

 struct dirent * dir=NULL;
 struct stat s;
 int fd;

 char str[100];
 sprintf(str,"%s/",fdname);

 char filestr[100];
 sprintf(filestr,"%s",fname);

 char str1[300];
 char nums[30];
 char * buff;
 char namearr[100];
 
 DIR * pd=opendir(str);
 if(pd==NULL)
 {
  printf("Error:Unable to open %s directory\n",fdname);
  return 0;
 }

 int fdd=open(filestr,O_WRONLY|O_CREAT,0x777);
 if(fdd==-1)
 {
  printf("Error:Unable to open %s file\n",fname);
  return 0;
 }

 while((dir=readdir(pd))!=NULL)
 {
	  if(((strcmp(dir->d_name,"."))==0)||((strcmp(dir->d_name,".."))==0))
	   {
	     continue;
	   }

	   sprintf(str1,"%s%s",str,dir->d_name);////////////

	   printf("%s\n",str1);

	   if((stat(str1,&s))==-1)
	   {
	    printf("Error:Unable to fetch information of file\n");

	    switch(errno)
	    {
	     case EACCES:
			perror("EACCES error\n");
			break;
	     case EBADF:
			perror("EBADF error\n");
			break;
	     case EFAULT:
		 	perror("EFAULT error\n");
	    		break;
	     case ELOOP :
			 perror("ELOOP error\n");
		     	 break;
	     case ENAMETOOLONG :
			perror("ENAMETOOLONG error\n");
	     		break;
	     case ENOENT:
			perror("ENOENT error\n");
			break;     
	     case ENOMEM:
			perror("ENOMEM error\n");
			break;
	     case ENOTDIR:
			perror("ENOTDIR error\n");
			break;
	     case EOVERFLOW:
			perror("EOVERFLOW error\n");
			break;
	     }
	    
	   return 0;
	   }

	   if(S_ISREG(s.st_mode))
	   { 
	     
	     fd=open(str1,O_RDONLY);

	     strcpy(namearr,dir->d_name);

	     write(fdd,namearr,100);

	     sprintf(nums,"%ld",s.st_size);

	     write(fdd,nums,30);

	     buff=(char *)malloc(s.st_size);

	     read(fd,buff,s.st_size);

	     write(fdd,buff,s.st_size);

	     close(fd);

	     free(buff);
	   }
  }

 close(fdd);
 return 1;
}//end of pack function
