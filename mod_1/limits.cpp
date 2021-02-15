#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<iostream>
#include<unistd.h>
using namespace std;

int main()
{
int res; 

if((res=sysconf(_SC_OPEN_MAX))==-1) // Maximum number of opened files per process
    perror("sysconf");
else
    cout<<"OPEN_MAX:"<<res<<endl;

if((res=pathconf("/",_PC_PATH_MAX))==-1)  //Maximum length of a pathname (in bytes)
    perror("pathconf");
else
    cout<<"max path name:"<<(res+1)<<endl;

// ch-own - change ownership
if((res=fpathconf(0,_PC_CHOWN_RESTRICTED))==-1) // The _POSIX_CHOWN_RESTRICTED value 
    perror("fpathconf");
else
    cout<<"chown_restricted for stdin:"<<res<<endl;

return 0;
}