#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
	// P1 es padre de P2 y P3
	//salidas posibles: AAA,BBB,CCC,CCC . AAA,CCC,CCC,BBB . AAA,CCC,BBB,CCC. Porque despues de crear el primer hijo, cualquiera el padre o el hijo puede empezar primero.
	pid_t pid1, pid2;
	printf("AAA \n");

	pid1 = fork();
	if (pid1==0)
	{
		printf("BBB \n");
	}
	else
	{
		pid2 = fork();
		if(pid2 != 0){
			wait(NULL);
			wait(NULL);
		}
		printf("CCC \n");
	}
	exit(0);
}
