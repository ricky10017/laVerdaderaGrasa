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