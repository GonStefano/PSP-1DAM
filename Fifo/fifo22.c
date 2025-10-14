#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(){
	int fp1;
	int numero, factorial, i;
	char buffer[10];
	
	
	mkfifo("PIPE02",0666);
	
	fp1 = open("PIPE02",O_RDONLY);
	
	read(fp1,buffer,sizeof(buffer));
	
	close(fp1);
	
	numero = atoi(buffer);
	factorial = 1;
	i =1;
	while(i <= numero)
	{
		factorial *= i;
		i++;
	}
	memset(buffer,0,sizeof(buffer));
	
	int fp2 = open("PIPE02", O_WRONLY);
	sprintf(buffer, "%d",factorial);
	printf("fifo22: Enviando el factorial\n");
	write(fp2,buffer,strlen(buffer));
	
	close(fp2);

	return(0);
}
