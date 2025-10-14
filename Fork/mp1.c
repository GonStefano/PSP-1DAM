#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

void main(){

	pid_t pid;
	
	pid = fork();
	
	if(pid == 0){
		printf("Proceso hijo: Stefano gonzalez. \n");
	}else{
		wait(NULL);
		printf("Soy el proceso padre y mi PID %d, y el de mi hijo es %d \n",getpid(),pid);
	}
	exit(0);
}
