//C Program to create new process using Linux API system calls fork() and exit()
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    
    // Create new process using fork()
    pid = fork();
    
    if (pid < 0) {
        // Fork failed
        printf("Fork failed!\n");
        exit(1);
    }
    else if (pid == 0) {
        // Child process
        printf("CHILD PROCESS:\n");
        printf("Child PID: %d\n", getpid());
        printf("Child is exiting now...\n");
        exit(0);  // Child process exits
    }
    else {
        // Parent process
        printf("PARENT PROCESS:\n");
        printf("Parent PID: %d\n", getpid());
        printf("Created child with PID: %d\n", pid);
        printf("Parent is exiting now...\n");
        exit(0);  // Parent process exits
    }
    
    return 0;
}