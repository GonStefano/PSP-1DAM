#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdio.h>

void main(){
	pid_t pid;
	
	int fd1[2];
	int fd2[2];
	
	pipe(fd1);
	pipe(fd2);
	
	int dni;
	char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
	char letra;
	
	pid = fork();
	if(pid == 0){
		close(fd1[0]);
		printf("Introduce tu DNI:");
		scanf("%d", &dni);
		write(fd1[1],&dni,sizeof(dni));
		close(fd2[1]);
		read(fd2[0],&letra,sizeof(letra));
		printf("%d%c",dni,letra);
	}else{
		close(fd1[1]);
		read(fd1[0],&dni,sizeof(dni));
		dni %= 23;
		letra = letras[dni];
		close(fd2[0]);
		write(fd2[1],&letra,sizeof(letra));
		
		wait(NULL);
	}
}
