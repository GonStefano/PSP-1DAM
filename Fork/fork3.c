#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
	pid_t pid2, pid3, pid4, pid5, pid6, pidAbu2, pidAbu34, pidAbu56;
	
	pidAbu2 = getppid();
	pid2 = fork();
	if(pid2 == 0){
		pidAbu34 = getppid();
		pid3 = fork();
		if(pid3 == 0){
			pidAbu56 = getppid();
			pid5 = fork();
			if(pid5 > 0){
				wait(NULL);
				printf("Mi pid es %d y el de mi abuelo es: %d\n",getpid(),pidAbu34);
			}
			else{
				printf("Mi pid es %d y el de mi abuelo es: %d\n",getpid(),pidAbu56);
			}
		}else{
			wait(NULL);
			pid4 = fork();
			if(pid4 == 0){
				pidAbu56 = getppid();
				pid6 = fork();
				if(pid6 > 0){
					wait(NULL);
					printf("Mi pid es %d y el de mi abuelo es: %d\n",getpid(),pidAbu34);
				}else{
					printf("Mi pid es %d y el de mi abuelo es: %d\n",getpid(),pidAbu56);
				}
			}else{
				wait(NULL);
				printf("Mi pid es %d y el de mi abuelo es: %d\n",getpid(),pidAbu2);
			}
		}
	}else{
		wait(NULL);
		printf("Mi pid es %d\n",getpid());
	}
	exit(0);
}
