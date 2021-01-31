# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
int main()
{
 int fd;
fd = open("t1.txt",O_RDONLY,0);
printf(" fd is %d /n", fd);
 close(fd);
}//Even though file is open in read only mode, the trunc flag will remove all the
// contents of the file