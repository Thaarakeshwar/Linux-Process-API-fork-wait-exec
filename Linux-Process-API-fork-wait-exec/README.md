# Linux-Process-API-fork-wait-exec-
Ex02-Linux Process API-fork(), wait(), exec()
# Ex02-OS-Linux-Process API - fork(), wait(), exec()
Operating systems Lab exercise


# AIM:
To write C Program that uses Linux Process API - fork(), wait(), exec()

# DESIGN STEPS:

### Step 1:

Navigate to any Linux environment installed on the system or installed inside a virtual environment like virtual box/vmware or online linux JSLinux (https://bellard.org/jslinux/vm.html?url=alpine-x86.cfg&mem=192) or docker.

### Step 2:

Write the C Program using Linux Process API - fork(), wait(), exec()

### Step 3:

Test the C Program for the desired output. 

# PROGRAM:

## C Program to create new process using Linux API system calls fork() and getpid() , getppid() and to print process ID and parent Process ID using Linux API system calls

nano program.c

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

gcc program.c -o program

./program

## OUTPUT
![Alt text](program.png)

## C Program to execute Linux system commands using Linux API system calls exec() , exit() , wait() family

nano exec_program.c

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

gcc exec_program.c -o exec_program

./exec_program

## OUTPUT:
![Alt text](exec_program.png)

## RESULT:
The programs are executed successfully.
