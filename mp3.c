#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

void main(){
	pid_t pid2, pid3;
	
	pid2 = fork();
	
	if(pid2 != 0){
		pid3 = fork();
	}
	
	if(pid2 == 0){
		sleep(10);
		printf("P2: Despierto\n");
	}else if(pid3 == 0){
		printf("Soy el proceso p3 y mi PID es: %d. El PID de mi padre es: %d \n",getpid(),getppid());
	}else{
		wait(NULL);
		wait(NULL);
		printf("Proceso P1\n");
	}
	exit(0);
}
