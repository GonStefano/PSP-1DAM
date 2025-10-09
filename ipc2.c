#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
	int fd[2];
	char buffer;
	pid_t pid;
	int num1;
	int num2;
	int num3;
	
	
	
	pipe(fd);
	
	pid = fork();
	
	if(pid == 0){
		close(fd[1]);
		read(fd[0],&num1,sizeof(num1));
		read(fd[0],&num2,sizeof(num2));
		read(fd[0],&num3,sizeof(num3));
		read(fd[0],&buffer,sizeof(buffer));
		printf("Numero a sumar: %i \n",num1);
		printf("Numero a sumar: %i \n",num2);
		printf("Numero a sumar: %i \n",num3);
		printf("Recivido caracter %c \n",buffer);
		if(buffer == '+'){
			int suma = num1+num2+num3;
			printf("la suma total es igual a: %i \n",suma);
		}
		
	}else{
		close(fd[0]);
		num1 = 25;
		num2 = 18;
		num3 = 67;
		buffer = '+';
		write(fd[1],&num1,sizeof(num1));
		write(fd[1],&num2,sizeof(num2));
		write(fd[1],&num3,sizeof(num3));
		write(fd[1],&buffer,sizeof(buffer));
		wait(NULL);
	}	
	
	exit(0);
}
