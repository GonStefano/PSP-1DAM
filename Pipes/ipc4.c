#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void main(){
	pid_t pid;
	time_t t;
	int numero1;
	int factorial=1;
	
	int fd[2];
	int  fd1[2];
	pipe(fd);
	pipe(fd1);
	
	pid = fork();
	
	if(pid == 0){
		close(fd[1]);
		read(fd[0],&numero1,sizeof(numero1));
		int i = 1;
		printf("El proceso padre genera el numero %d en el pipe1 \n",numero1);
		while(i <= numero1){
			factorial *= i;
			i++;
		}
		close(fd1[0]);
		write(fd1[1],&factorial,sizeof(factorial));

	}else{
		close(fd[0]);
		srand((unsigned) time(&t));
		numero1=rand() % 10;
		write(fd[1],&numero1,sizeof(numero1));
		close(fd1[1]);
		read(fd1[0],&factorial,sizeof(factorial));
		printf("El factorial calculado por el proceso hijo: %d != %d \n",numero1, factorial);
		wait(NULL);
	}
	exit(0);
}
