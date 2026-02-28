#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    
    // Print parent process IDs
    printf("Parent Process - Before fork()\n");
    printf("Process ID (PID): %d\n", getpid());
    printf("Parent Process ID (PPID): %d\n", getppid());
    printf("----------------------------------------\n");
    
    // Create new process
    pid = fork();
    
    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("\nCHILD PROCESS:\n");
        printf("Process ID (PID): %d\n", getpid());
        printf("Parent Process ID (PPID): %d\n", getppid());
    }
    else {
        // Parent process
        printf("\nPARENT PROCESS:\n");
        printf("Process ID (PID): %d\n", getpid());
        printf("Parent Process ID (PPID): %d\n", getppid());
        printf("Child Process ID: %d\n", pid);
        
        // Wait for child to complete
        wait(NULL);
    }
    
    return 0;
}
