#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<unistd.h>
int main()
{
#ifdef _POSIX_VERSION
printf("System conforms to POSIX: %ld \n",_POSIX_VERSION);
#else
prtinf("_POSIX_VERSION undefined\n");
#endif
return 0;
}