#include<stdio.h>
#include<unistd.h>
int main(int argc, char* argv)
{
if(link('t1.txt','t.txt')==-1)
{
printf("link error"); return 1;
}
else{
    printf('Link created\n');
}
return 0;
}