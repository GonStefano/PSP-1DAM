#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

void main()
{
	//El padre empieza ejecutando desde la linea 1 hasta la 8. En la 8 se crea un proceso hijo y por la condicional solo el padre puede entrar.Y en el else entra el hijo hasta que todos salen.
	//P1 es padre de P2
	printf("CCC \n");
	if (fork()!=0)
	{
		wait(NULL);
		printf("AAA \n");
	} else printf("BBB \n");
	exit(0);
}
//muestra CCC,AAA,BBB. Y tambien puede mostrar CCC,BBB,AAA. con el wait solo muestra CCC,BBB,AAA
