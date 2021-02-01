#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
int main()
{
struct flock f1;
int fd;
//initializing locking parameters
f1.l_pid = getpid();
f1.l_type = F_WRLCK; // write lock
f1.l_whence = SEEK_SET; // from beginning
f1.l_start = 0;
f1.l_len = 0; // to the end of the file
fd= open("k1",O_WRONLY);
// apply lock
if(fcntl(fd,F_SETLK,&f1)==-1)
{
perror("fcntl");
exit(1);
}
getchar();
printf("got lock");
printf("pid of the process %ld",getpid());
getchar();
f1.l_type =F_UNLCK; //set to unlock the same region
if(fcntl(fd,F_SETLK,&f1) == -1)
{
perror("fcntl");
exit(1);
}
printf("Unlocked\n");
close(fd);
return 0;
}
