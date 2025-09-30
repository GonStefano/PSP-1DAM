#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
	pid_t pid2, pid3, pid4;
	
	pid2 = fork();
	if(pid2 == 0){
		pid3 = fork();
		if(pid3 == 0){
			pid4 = fork();
			if(pid4 > 0){
				wait(NULL);
			}
		}else{
			wait(NULL);
		}
	}
	else{
		wait(NULL);
	}
	int suma = getpid() + getppid();
	printf("Mi PID es %d, y el de mi padre es: %d. Y la suma es: %i \n",getpid(), getppid(),suma);
	exit(0);
}
