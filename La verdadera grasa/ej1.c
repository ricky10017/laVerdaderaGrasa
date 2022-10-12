#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main (void){
    pid_t pid;
    pid = fork();
    if(pid < 0){
        fprintf(stderr,"Error creating fork");
        exit(EXIT_FAILURE);
    }
    else if(pid == 0){
        printf("Child 1\n");
        fflush(stdout);
        pid = fork();
        waitpid(pid, NULL, WUNTRACED);
        if(pid < 0){
            fprintf(stderr,"Error creating fork");
            exit(EXIT_FAILURE);
        }        
        else if(pid == 0){
            sleep(3);
            printf("Child 2\n");
            fflush(stdout); 
        }
    }
    else{
        waitpid(pid, NULL, WUNTRACED);        
        printf("All done!\n");
        return 0;
    }
}















// #define CURRENT 1
// #define PARENT 2

// int my_getpid() {
//     if(m_in.m4_l1 ==1){
//         return mproc[who_p].mp_pid;
//     } 
//         return mproc[mp->mp_parent].mp_pid;
// }

// int mygetpid(long integer) {  
//     message m;
//     m.m_type =M4;
//     m.m4_l1 = integer;
//     return _syscall(PM_PROC_NR,MYCALL,&m);
// }









// int sem_wait(semaphore * sem)

// {

// pthread_mutex_lock(&sem_mutex);

// if(sem->value == 0)

// {

// pthread_cond_wait(&sem_cond, &sem_mutex);

// }

// sem->value -=1;

// pthread_mutex_unlock(&sem_mutex_unlock(&sem_mutex);

// }






// if(argc == 2){

// fprintf(stderr,”usage: %d processes\n”,argv[0]);

// return 1;

// }

// n = 

// for( int i = 0; i < n; i++){

// if(fork() == 0{

// fprintf(stderr, "i: %d process ID: %ld parent ID: %ld child ID: %ld ", i, (long)getpid(), (long)getppid(), (long)childpid);

// exit(0);

// }

// else if (fork() < 0){

// fprintf(stderr, "i: %d process ID: %ld parent ID: %ld child ID: %ld ", i, (long)getpid(), (long)getppid(), (long)childpid);

// }

// else {

// fprintf(stderr, "i: %d process ID: %ld parent ID: %ld child ID: %ld ", i, (long)getpid(), (long)getppid(), (long)childpid);

// exit(0);

// }

// }

// return 0;

// }