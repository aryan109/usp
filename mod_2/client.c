#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
int main()
{
struct flock f1={ F_WRLCK, SEEK_END ,0,100,0};
int fd;
char a;
fd= open("k1",O_RDWR,0);
// check whether it has been locked
if(fcntl(fd,F_GETLK,&f1) == -1)
{
perror("fcntl");
exit(1);
}
// if it is locked display
if(f1.l_type == F_RDLCK)
printf("\n read lock");
if(f1.l_type == F_WRLCK)
printf("\n Write lock");
printf("pid process= %d", f1.l_pid);
if(f1.l_type == F_UNLCK)
{
printf("\n no lock");
// if it is not locked –lock the file
fcntl(fd,F_SETLK,&f1);
lseek(fd, -50,SEEK_END);
printf("contents of file is \n");
// display the contents
while(read(fd,&a,1)>0)
printf("%c",a);
f1.l_type = F_UNLCK;
fcntl( fd, F_SETLK, &f1);
 }
return 0;
}