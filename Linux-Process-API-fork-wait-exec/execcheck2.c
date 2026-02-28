//C Program to execute Linux system commands using Linux API system calls exec() family
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    int status;
    
    pid = fork();
    
    if(pid == 0) {
        printf("Child executing Linux command...\n");
        execlp("ls", "ls", "-l", NULL);
        exit(0);
    }
    else if(pid > 0) {
        wait(&status);
        printf("Parent: Child completed\n");
        exit(0);
    }
    else {
        printf("Fork failed\n");
        exit(1);
    }
    
    return 0;
}