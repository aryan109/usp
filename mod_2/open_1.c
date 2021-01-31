# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
int main()
{
 int fd;
 fd = open("t1.txt", O_WRONLY|O_CREAT,0);
 printf("fd is %d \n",fd);
 close(fd);
} // Assuming that t.txt does not exist above program creates the file t.txt.