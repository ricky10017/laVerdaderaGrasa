#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int threads;
int matrix_scalar;
pthread_t *threadsArr;

struct matrix{
    int data[100][100];
    int size1;
    int size2;
};

struct matrix solution;

void *runner(void *param){
    int col = (* (int *) param);
    for (int i = 0; i < solution.size1; ++i) {
        solution.data[col][i] *= matrix_scalar;
    }        
}

void matrixOperation(int scalar, struct matrix X, struct matrix Y){    
    if (X.size1 != X.size2 || Y.size1 != Y.size2 || X.size2 % 2 != 0) {
        printf("ILLEGAL OPERATION\n");
        return;
    }
    else{
        threads = X.size1;
        solution.size1 = X.size1;
        solution.size2 = X.size2;
        matrix_scalar = scalar;
        // Apply sum to matrix
        for (int x = 0; x < X.size1; ++x) {
            for (int y = 0; y < Y.size1; ++y) {
                solution.data[x][y] = X.data[x][y] + Y.data[x][y];                
            }
        }
        // Apply scalar to each row with a pthread
        threadsArr = (pthread_t*) malloc(sizeof(pthread_t) * threads);
        for (int i = 0; i < threads; ++i) {
            pthread_create(&threadsArr[i], NULL, runner, (void *) &i);
        }
        for (int i = 0; i < threads; ++i) {
            pthread_join(threadsArr[i], NULL);
        }
        printf("Result = \n[");        
        for (int x = 0; x < X.size1; ++x) {
            printf("[");
            for (int y = 0; y < Y.size1; ++y) {
                double val = (double) solution.data[x][y]; // Cast to double because the print in moodle appears as double instead of int
                if (y + 1 == Y.size1) {
                    printf("%lf]", val);
                }
                else {
                    printf("%lf, ", val);
                }                
            }
            if (x + 1 == X.size1) {
                printf("]\n");
            }
            else {
                printf(",\n");
            }
        }
    }
    return;
}










// Teoria Examen 1 Operating Systems:

// 1.	In which mode does System calls run?
// -	Only the Kernel Mode

// 2.	_______ provides an interface to the services provided by an operating system. 
// -	System Calls 

// 3.	Mac OS X adopts _______ .
// -	Hybrid Structure 

// 4.	Mach OS adopts ________.
// -	Microkernel Structure. 

// 5.	Microkernels use ______ for communication.
// -	Message Passing 

// 6.	Which of the following statements is correct?
// A.	An operating system provides an environment for the execution of programs. 
// B.	An operating system manages system resources 
// C.	Operating systems must provide both protection and security. 

// 7.	Application programmers typically use ____ to access the services provided by OS.
// -	API

// 8.	A Microkernel is a kernel _____.
// -	 That is stripped of all nonessential components.    
  
// 9.	Which of the following methods limits the number or length of parameters being passed to the OS? 
// -	Register 

// 10.	In a virtual machine, each program believes that it has ___.
// -	Its own memory. 

// 11.	Most modern Operating System adopt ____ .
// -	Modular Structure.

// 12.	Privileged instructions may be executed by ___. 
// -	Only the Kernel mode. 


// 13.	Which of the following methods are used to pass parameters to the OS?
// A.	Register 
// B.	Block 
// C.	Stack 
// 14.	Which one of the followings is NOT the goals of OS?
// A.	Manage data transmission over the internet. 
// 15.	The hardware/user gap is bridged by the OS or by other system software. Which of the following task does NOT require OS support? 
// A.	Change the layout of a document. 

// 16.	In which mode does API run?
// -	Only the User Mode 

// 17.	A process is in _____ when its being created. 
// -	New State 

// 18.	A CPU scheduler can only select a process in ____ state to execute on the CPU? 
// -	Ready State 

// 19.	When a CPU scheduler selects a process to run on the CPU, the state of this process is changed ___ . 
// -	From Ready to Running State 

// 20.	Which of the following info is contained in Process Control Block?
// A.	Process state 
// B.	Process counter 
// C.	Registers 
// D.	Process number (ID)


// 21.	The _____ of a process contains temporary data such as function parameters, return addresses, and local variables. 
// -	Stack 

// 22.	Multiple child processes are created by the same parent program. Which one of the following is true? 
// A.	Only text sections are equivalent. 

// 23.	Can a program be running in multiple processes? 
// -	Yes

// 24.	A process is running on the CPU, when its CPU time slice is up, the state of this process is changed ____ 
// -	From running to ready 

// 25.	A process is in _____ when it finished execution. 
// -	Terminated state. 

// 26.	After a new process is successfully created, the state of this process is changed ____ ? 
// -	From new to ready. 

// 27.	A process is running on the CPU, when this process request to print data, the state of this process is changed ___ 
// -	From running to waiting. 

// 28.	A process is in ____ when it is waiting for an input signal.
// -	Waiting state. 

// 29.	The ____ of a process contains globe variables. 
// -	Data section. 

// 30.	If a process uses more time in computation than doing input/output, this process is a  ___ .
// -	 CPU- bound process. 

// 31.	After a process complete its execution, the state of this process is changed ___. 
// -	From running to terminated. 

// 32.	The ____ of a process contains program code. 
// -	Text section. 

// 33.	When a process finishes data printing, the state of this process is changed ___.
// -	From waiting to ready. 

// 34.	A process is in ___ when it is running on the CPU. 
// -	Running state. 

// 35.	A process is in ___ when it has every resource except the CPU. 
// -	Ready state. 

// 36.	If a process spends more time doing input and output than computation, this process is a ___ .
// -	Input/output bound process.

// 37.	Which of the following statements  about context switch is true? 
// A.	Context switch time is overhead. 

// 38.	Imagine that a host with IP addres 150.55.66.77 wishes to download a file from the web server at IP addres 202.28.15.123. Select a valid socket pair for a connection between this pair of hosts. 
// -	150.55.66.77:2000 and 202.28.15.123:80

// 39.	Which of the following statements is true? 
// A.	Shared memory is typically faster than message passing. 

// 40.	The exec() system call creates a new process. 
// -	False 

// 41.	Selecting which job should be brought into memory is ____ .
// -	Long term scheduler.

// 42.	Local procedure calls in windows are similar to Remote Procedure Calls.
// -	True.

// 43.	Selecting which process should obtain CPU and execute next is ___. 
// -	Short term scheduler. 

// 44.	Swapping out or swapping in partially executed processes is ___ .
// -	Medium term scheduler. 

// 45.	Which of the following statements about context switch is true? 
// A.	Independent process cannot affect the execution of another process. 

// 46.	Non-blocking Send 
// -	Is asynchronous 

// 47.	Ordinary pipes in windows require a parent-child relationship between the communicating processes. 
// -	True 

// 48.	Blocking Receive.
// -	Is synchronous. 

// 49.	Named pipes are unidirectiolans. 
// -	False

// 50.	Which of the following statements about context switch is true? 
// A.	Cooperating processes need interprocess communication. 

// 51.	Which of the following relationship on resource sharing is possible. 
// A.	Parent and children share all resources. 
// B.	Children share part of the parents resources. 
// C.	Parent and children share no resources. 
// D.	A and B 
// E.	B and C

// 52.	The information or messages exchanged in _____ is pure data packet. 
// -	Socket Communication. 

// 53.	Shared memory is a more appropriate IPC mechanism than message passing for distributed systems. 
// -	False 

// 54.	Pthreads refers to ___. 
// -	A specification for thread behavior. 

// 55.	Windows 10 uses the ____ . 
// -	One to one model 

// 56.	The ___ model maps many user-level threads to one kernel thread.
// -	Many to one.

// 57.	A thread is composed of a thread ID, program counter, register set, and a heap.
// -	False 

// 58.	In Pthreads, a parent uses the pthread_join() function to wait for its child thread to complete. What is the equivalent function in Win32?
// -	WaitForSingleObject()

// 59.	A ___ provides an API for creating and managing threads. 
// -	Threads library.

// 60.	LWP is ___.
// -	Short for lightweight process. 

// 61.	The ______ model multiplexes many user-level threads to a smaller or equal number of kernel threads. 
// -	Many to many 

// 62.	The ___ multithreading model multiplexes one user-level thread to one kernel thread. 
// -	One to one 

// 63.	____ Is a thread library for Solaris that maps many user-level threads to one kernel thread. 
// -	Green threads
