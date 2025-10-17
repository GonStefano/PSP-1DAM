#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int num1,num2;
char buffer[100];

void senal( int numsenal )
{
	memset(buffer,0,sizeof(buffer));
	time_t ahora;
	struct tm *tiempoLocal;
	time(&ahora);
	
	tiempoLocal = localtime(&ahora);
	printf("Señal de alarma  recibida a las  %02d:%02d:%02d \n",
            tiempoLocal->tm_hour,
            tiempoLocal->tm_min,
            tiempoLocal->tm_sec);
 	
}

int main()
{
	pid_t pid;
	signal(SIGUSR1,senal);
	printf("¿Cuantas veces sonará la alarma?:");
	scanf("%d",&num1);
	printf("¿Cada cuántos segundos se repetirá la alarma?:");
	scanf("%d",&num2);
	pid = getpid();
	printf("Alarma activada\n");
	for(int i=0 ;i<num1;i++){
		kill(pid,SIGUSR1);
		sleep(num2);
	}
  return 0;
}
