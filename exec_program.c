#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    int status;
    
    pid = fork();
    
    if (pid < 0) {
        printf("Fork failed!\n");
        exit(1);
    }
    else if (pid == 0) {
        // Child process - using exec()
        printf("Child executing 'ls' command...\n");
        execlp("ls", "ls", "-l", NULL);
        exit(0);
    }
    else {
        // Parent process - using wait()
        printf("Parent waiting for child...\n");
        wait(&status);
        printf("Child process completed\n");
        exit(0);
    }
    
    return 0;
}

