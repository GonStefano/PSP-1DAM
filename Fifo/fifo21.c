#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

int main(void){
	char buffer[10];
	int fp1;
	char numero[10];
	time_t t;
	int num;
	
	mkfifo("PIPE02",0666);
	
	fp1 = open("PIPE02",O_WRONLY);
	
	srand((unsigned) time(&t));
	num=rand()%10;
	sprintf(numero, "%d",num);
	
	printf("fifo21: Enviando numero aleatorio entre el 1-10\n");
	write(fp1,numero,strlen(numero));
	close(fp1);
	
	int fp2 = open("PIPE02",O_RDONLY);
	memset(buffer,0,sizeof(buffer));
	read(fp2,buffer,sizeof(buffer));
	printf("fifo21: Factorail recibido: %s \n",buffer);
	
	close(fp2);
	
	unlink("PIPE02");

	return 0;
}
