#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<unistd.h>

int unpack(char fname[50],char fdname[50]);
int pack(char fdname[50],char fname[50]);
