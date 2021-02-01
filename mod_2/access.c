#include<unistd.h>
#include<stdio.h>
// example for access API
int main(){
    if(access("./t1.txt", F_OK)==-1)
        printf("file does not exists\n");
    else
        printf("file exists\n");

    if(access("./t1.txt", R_OK)==-1)
        printf("file does not have read permission\n");
    else
        printf("file have read permission\n");

    if(access("./t1.txt", W_OK)==-1)
        printf("file does not have write permission\n");
    else
        printf("file have write permission\n"); 
        
    if(access("./t1.txt", X_OK)==-1)
        printf("file does not have execute permission\n");
    else
        printf("file have execute permission\n");
    return 0;
}