#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

FILE *archivo;
char buffer[100];

void fun_signal( int numsenal )
{
	memset(buffer,0,sizeof(buffer));
	printf("Fichero salidas.txt");
	time_t ahora;
	struct tm *tiempoLocal;
	time(&ahora);
	
	tiempoLocal = localtime(&ahora);
	sprintf(buffer, "Señal SIGINT recibida a las  %02d:%02d:%02d",
            tiempoLocal->tm_hour,
            tiempoLocal->tm_min,
            tiempoLocal->tm_sec);
            
        archivo = fopen("salidas.txt","a");
            
	fprintf(archivo, "%s\n", buffer);
	
	fclose(archivo);
 	
}

int main()
{
	signal(SIGINT,fun_signal);
	while(1){

		pause;
	}
  return 0;
}
