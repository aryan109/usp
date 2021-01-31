#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
int main()
{
 int file=0;
 if((file=open("testfile.txt",O_RDONLY)) < -1) 
 return 1;
 char buffer[19];
 if(read(file,buffer,19) != 19) return 1; 
 printf("Starting/nBuffer: %s\n",buffer); // prints first 19 characters from file
 if(lseek(file,10,SEEK_SET) < 0) return 1; // move pointer 10 position forward
 if(read(file,buffer,19) != 19) return 1;
 printf("after Lseek \nbuffer: %s\n",buffer); // prints 19 characters from the current pointer position 
 return 0;
}
