#include<stdio.h>
int main()
{
int f_ret1 = vfork();
printf("\n hello USP 1\n");
printf("Returned from vfork1 is: %d",f_ret1);

int f_ret2 = vfork();
printf("\n hello USP 2\n");
printf("Returned from vfork2 is: %d \n",f_ret2);
}
