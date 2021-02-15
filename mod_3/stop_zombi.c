# include <stdio.h>
# include <stdlib.h>

int main(void)
{
pid_t pid;
if ((pid = fork()) < 0)
{
err_sys("fork error");
}
else
if (pid == 0)
{ /* first child */
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else
        if (pid > 0)
            exit(0);/* parent from second fork == first child */
    /*
    We're the second child; our parent becomes init assoon as our real parent calls exit() in the
    statementabove. Here's where we'd continue executing, knowing thatwhen we're done, init
    will reap our status.
    */
    sleep();
    printf("second child, parent pid = %d\n", getppid()); exit(0);
}
if (waitpid(pid, NULL, 0) != pid) /* wait for first child */
    printf("waitpid error");
/*
We're the parent (the original process); we continue executing, knowing that we're not the
parent of the second child.
*/
exit(0);
}
