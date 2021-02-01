#include<stdio.h>
int main()
{
int f_ret1 = fork();
printf("\n hello USP 1\n");
printf("Returned from fork1 is: %d",f_ret1);

int f_ret2 = fork();
printf("\n hello USP 2\n");
printf("Returned from fork2 is: %d \n",f_ret2);
}
