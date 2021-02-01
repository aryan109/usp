#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<pwd.h>
# include<stdio.h>
int main(int argc, char *argv[ ])
{
if(argc>3)
{
 printf( "usage:%s  <usr_name><file>. \n",argv[0]);
return 1;
}
struct passwd *pwd = getpwuid(argv[1]) ;
uid_t UID = pwd ? pwd -> pw_uid : -1 ;
struct stat statv;

printf( "UID: %d", UID); 
if (UID == (uid_t)-1)
 printf(  "Invalid user name"); 
else 
    for (int i = 2; i < argc ; i++)
        if (stat(argv[i], &statv)==0)

if (chown(argv[i], UID,statv.st_gid)) 
    perror ("chown");
else
    perror ("stat");

return 0;
}
