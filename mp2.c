#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

void main(){
	pid_t pid, pid_nieto;
	
	pid = fork();
	
	if(pid==0){
		pid_nieto = fork();
		if(pid_nieto==0){
			printf("Soy el proceso P3, mi PID es: %d. El PID de mi padres es %d \n",getpid(),getppid());
		}else{
			wait(NULL);
			printf("Soy el proceso P2, mi PID es: %d. El pid de mi padre es %d \n",getpid(),getppid());
		}
	}else{
		wait(NULL);
		printf("Soy el proceso P1, mi PID es: %d. El pid de mi hijo es %d \n",getpid(),pid);
	}
	exit(0);
}
