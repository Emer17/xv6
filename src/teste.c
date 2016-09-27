//A test for the Scheduling, later become Lottery Scheduling


#include "types.h"      //maybe needed to use some types of variables
#include "user.h"       //functios like printf and syscalls

#define STDOUT 1        //following the standard nomenclature for xv6 output
#define CHILDS 30
#define TIMER 112345678

int main(){
    int pid;
    int i;
    for (i=0;i<CHILDS;i++){
        if(i<(CHILDS/3)){
            pid=fork(1);
        }else if(i>=(CHILDS/3) &&  i<(2*(CHILDS/3))){
            pid=fork(10);
        }else{
            pid=fork(45);
        }if(pid == 0){
            for(i = TIMER;i>0;i--);
            exit();
        }
        
    }
    while(1){
        pid=wait();
        if(pid<0)break;
        printf(STDOUT,"Child %d finished\n",pid );      
    }
    
    
    exit();
}