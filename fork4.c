#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
	pid_t pid2, pid3, pid4, pid5;
	
	int acumulado = getpid();
	pid2 = fork();
	if(pid2 == 0){
		pid5 = fork();
		if(pid5 == 0){
			
		}else{
			wait(NULL);
			
		}
	}else{
		wait(NULL);
		pid3 = fork();
		if(pid3 == 0){
			pid4 = fork();
			if(pid4 == 0){
			
			}else{
				wait(NULL);
			}
		}else{
			wait(NULL);
		}
	}
	
	if((pid2 == 0 || pid3 == 0) && pid4 != 0 && pid5 != 0){
		if((getpid() % 2) == 0){
			acumulado += 10;
			printf("PID: %d, Acumulado: %i\n",getpid(),acumulado);
		}else{
			acumulado -= 100;
			printf("PID: %d, Acumulado: %i\n",getpid(),acumulado);
		}
	}
	exit(0);
}
