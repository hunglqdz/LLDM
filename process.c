// run this file in Ubuntu

#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main(){
    pid_t pid;
    pid = fork(); // fork a child process

    if(pid<0){ // error occurred
        fprintf(stderr,"Fork failed");
        return 1;
    }
    else if(pid==0){ // child process
        execlp("/bin/ls","ls",NULL);
    }
    else{ // parent process
        wait(NULL); // wait for child to complete
        printf("Child complete");
    }

    return 0;
}
