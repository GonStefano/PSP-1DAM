#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
//En mi caso siempre sera el mismo orden primero terminara P2,despues P4, despues P3 y por ultimo P1
	pid_t pid,pid2,pid3,pid4;

	pid2 = fork();
	if(pid2 != 0){
		wait(NULL);
		pid3 = fork();
		if(pid3 == 0){
			pid4 = fork();
			if(pid4 != 0){
				wait(NULL);
			}
		}else{
		wait(NULL);
		}
	}
		

	if((getpid() % 2) == 0){
		printf("Mi PID es: %d, y el de mi padre es: %d .\n",getpid(),getppid());
	}else{
		printf("Mi PID es: %d \n",getpid());
	}
	exit(0);
}
