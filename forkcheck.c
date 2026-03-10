#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    // Variable to store calling function's process id
    pid_t process_id;
    
    // Variable to store parent function's process id
    pid_t p_process_id;
    
    // getpid() - will return process id of calling function
    process_id = getpid();
    
    // getppid() - will return process id of parent function
    p_process_id = getppid();
    
    // Printing the process ids
    printf("The process id: %d\n", process_id);
    printf("The process id of parent function: %d\n", p_process_id);
    
    return 0;
}

