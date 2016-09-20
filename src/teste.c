#include "types.h"      //talvez seja necessario para usar alguns tipos de variaveis
#include "user.h"       //para usar funcoes como printf e syscalls

#define STDOUT 1       

int main(){
    int pid = fork(0);
    if(pid > 0){
        printf(STDOUT,"parent: child=%d\n", pid);
        pid = wait();
        printf(STDOUT,"child %d is done\n", pid);
    } else if(pid == 0){
        printf(STDOUT,"child: exiting\n");
        exit();
    } else {
        printf(STDOUT,"fork error\n");
    }
    exit();
}
