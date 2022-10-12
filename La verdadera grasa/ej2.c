#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main (void){    
    int currentChild = 0;
    int parentProc = getpid();
    printf("getpid %d\n", parentProc);
    pid_t childs[2];    
    for (int i = 0; i < 2; ++i) {
        currentChild++;
        int ppid = getppid();
        printf("getppid %d\n", ppid);
        if (ppid == parentProc) {
           childs[i] = fork();
        }
        else {
            if (currentChild == 2)
            sleep(3);
            printf("Child %d\n", currentChild);
            fflush(stdout);
        }  
    }    
    for (int i = 0; i < 2; ++i) {
        waitpid(childs[i], NULL, WUNTRACED);      
    }
    
    if (parentProc == getpid()){
    printf("All done!!!\n");
    }
    return 0;
}















// 1. which of the following has a critical processor feature that enabled operating systems to substantially improve protection and security?
// 	- supervisor mode
// 2. Which of the following is required to implement Remote Procedure Calls?
// 	- Marshaling of Parameters
// 3. which of the following characteristics of a producer/consumer pair would make each blocking read/write work like a rendezvous?
// 	- unbounded buffer
// 	- zero capacity buffer
// 	- bounded buffer
// 4. which of the following is false about threads?
// 	- user threads are mapped to cpu cores
// 5. which of the following is true about threads?
// 	- more than one kernel thread can be mapped to a single user thread
// 	- each user thread has a single program counter
// 	- if a thread is waiting for an I/O operation to complete, all other threads need to wait as well before they can be scheduled to run
// 	- it is always better to use threads, rather than processes, since they are lighter to context switch
// 6. When communicating with sockets, a client process initiates a request for a connection and is assigned a port by the host computer. Which of the following would be a valid port assignment for the host computer?
// 	- 1625 (ports under 500 are reserved for administrator)
// 7. Which of the following is not part of the thread context?
// 	- global variables
// 8. Which of the following is part of the thread context?
// 	- program counter
// 	- stack
// 	- processor state
// 9. The most common secondary storage device is ____________?
// 	- magnetic disk
// 10. Which of the following would be an acceptable signal handling scheme for a multithreaded program?
// 	- Deliver the signal to only certain threads in the process.
// 	- Deliver the signal to every thread in the process.
// 	- Deliver the signal to the thread which the signal applies.
// 11. In multithreaded programs, the kernel informs an application about certain events using a procedure known as an ____?
// 	- up-call
// 12. The most common technique for writing multithreaded Java programs is ___________.
// 	- implementing the runnable interface and defining its run() method
// 13. Which of the following would be an acceptable signal handling scheme for a multithreaded program?
// 	- Deliver the signal to only certain threads in the process
// 	- Deliver the signal to every thread in the process
// 	- Deliver the signal to the thread to which the signal applies
// 14. If the program terminates abnormally, a dump of memory may be examined by _________ to determine the cause of the problem.
// 	- debugger
// 15. The __________ refers to the number of processes in memory
// 	- degree of multiprogramming
// 16. A process may transition to the ready state by which of the following actions?
// 	- Completion of an I/O event
// 	- Awaiting its turn on the CPU
// 	- Newly-admitted process
// 17. A ___________ provides an API for creating and managing threads.
// 	- thread library
// 18. ​________ provide(s) an interface to the services provided by an operating system
// 	- System Calls
// 19. which of the following statements is correct?
// 	- An operating system provides an environment for the execution of programs
// 	- Operating systems must provide both protection and security
// 	- An operating system manages system resources
// 20. which of the following statements is incorrect?
// 	- Operating systems provide both command line as well as graphical user interfaces
// 21. Thread-local storage is data that _____.
// 	- is unique to each thread.
// 22. which of the following statements is true?
// 	- Shared memory is typically faster than message passing
// 23. which of the following statements is false?
// 	- shared memory is far more common in operating systems than message passing
// 	- message passing is typically faster than shared memory
// 	- message passing is most useful for exchanging large amounts of data
// 24. ​_______ is not considered a challenge when designing applications for multicore systems
// 	- Ensuring there is a sufficient number of cores
// 25. A _____ saves the state of the currently running process and restores the state of the next process to run
// 	- context switch
// 26. which of the following statements is false?
// 	- The difference in storage capacity between a mobile device and a laptop is shrinking
// 27. Pthreads refers to ___.
// 	- a specification for thread behavior.
// 28. Two important design issues for cache memory are _____.
// 	- size and replacement policy
// 29. A message-passing model is ______. 
// 	- easier to implement than a shared memory model for inter-computer communication
// 30. A clustered system _____. 
// 	- gathers together multiple CPUs to accomplish computational work