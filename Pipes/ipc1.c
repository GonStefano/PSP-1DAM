#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

void main(){
	int fd[2];
	char buffer[100];
	time_t hora;
	char *fecha;
	pid_t pid;
	
	pipe(fd);
	
	pid = fork();
	
	if(pid==0){
		close(fd[1]);
		printf("El hijo lee el pipe\n");
		read(fd[0],buffer,sizeof(buffer));
		printf("Tiempo del padre: %s \n",buffer);
	}else{
		close(fd[0]);
		//printf("El padre escribe en el pipe..\n");
		//write(fd[1], system("date"),20);
		//wait(NULL);
		

		
		time(&hora);
		fecha = ctime(&hora);
		printf("El padre escribe en el pipe.. \n");
		write(fd[1],fecha,strlen(fecha)+1);
		close(fd[1]);
		
		
		wait(NULL);
	}
	exit(0);
}
