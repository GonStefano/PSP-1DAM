#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int fd[2];
char buffer[10];

void senal_p2(int num_senal){
	int num;
	read(fd[0],buffer,sizeof(buffer));
	printf("Número par %s recibido por el proceso P2 con pid %d\n", buffer, getpid());
}

void senal_p3(int num_senal){
	int num;
	read(fd[0],buffer,sizeof(buffer));
	printf("Número impar %s recibido por el proceso P3 con pid %d\n", buffer, getpid());
}

int main()
{
	pid_t pid2,pid3;
	int num;
	pipe(fd);
	
	if((pid2 = fork()) == 0)
	{
		close(fd[1]);
		signal(SIGUSR1,senal_p2);
		while(1) pause;
	}
	
	if((pid3 = fork()) == 0)
	{
		close(fd[1]);
		signal(SIGUSR2,senal_p3);
		while(1) pause;
	}
	
	close(fd[0]);

	do{
	sleep(1);
	printf("Introduce numero:");
	scanf("%d", &num);
	sprintf(buffer, "%d", num);
	
	write(fd[1],buffer,sizeof(buffer));
	
	if(num == 0){
		printf("Mandando señal de terminación al proceso hijo P2 con pid %d\n", pid2);
		kill(pid2,SIGTERM);
		printf("Mandando señal de terminación al proceso hijo P3 con pid %d\n", pid3);
		kill(pid3,SIGTERM);
	}else if(num % 2 == 0){
		kill(pid2,SIGUSR1);
	}else{kill(pid3,SIGUSR2);}
	
		
	}while(num!=0);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
	printf("Fin proceso padre con pid %d\n",getpid());
  return 0;
}
