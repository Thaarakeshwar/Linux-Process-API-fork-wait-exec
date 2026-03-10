#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int status;
    
    printf("Running ps with execlp\n");
    if (fork() == 0) {
        execlp("ps", "ps", "-f", NULL);
        exit(1);
    }
    wait(&status);
    
    printf("Done.\n");
    return 0;
}

