#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void main(){
	int fd[2];
	char buffer;
	pid_t pid;
	int num1;
	int num2;
	time_t t;
	
	
	pipe(fd);
	
	pid = fork();
	
	if(pid == 0){
		close(fd[0]);
		srand((unsigned) time(&t));
		num1 = rand() % 50;
		num2 = rand() % 50;
		write(fd[1],&num1,sizeof(num1));
		write(fd[1],&num2,sizeof(num2));
	}else{
		wait(NULL);
		close(fd[1]);
		read(fd[0],&num1,sizeof(num1));
		read(fd[0],&num2,sizeof(num2));
		printf("%i + %i = %i \n",num1,num2, num1+num2);
		printf("%i - %i = %i \n",num1,num2, num1-num2);
		printf("%i * %i = %i \n",num1,num2, num1*num2);
		printf("%i / %i = %i \n",num1,num2, num1/num2);
	}	
	
	exit(0);
}
