#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
int main()
{
sigset_t sigmask;
sigemptyset(&sigmask); /*initialise set*/
if(sigprocmask(0,0,&sigmask)==-1) /*get current signal mask*/
{
    perror("sigprocmask");
    exit(1);
}
else
    sigaddset(&sigmask,SIGINT); /*set SIGINT flag*/

sigdelset(&sigmask, SIGSEGV); /*clear SIGSEGV flag*/

if(sigprocmask(SIG_SETMASK,&sigmask,0)==-1)
perror("sigprocmask");
}