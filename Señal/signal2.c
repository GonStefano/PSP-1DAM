/* El programa muestra cómo capturar una señal del sistema (en este caso SIGINT) 
   y cómo asignarle un manejador personalizado -> función que se ejecuta cuando llega la señal*/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int i=0;

void fun_signal(int signum){
  i += 5;
  printf("Han transcurrido %d segundos\n",i);
}


int main(){
  pid_t pid;
  signal(SIGUSR1,fun_signal);
  for(int i=1;;i++){    //Infinite loop
    sleep(5);
    kill(pid,SIGUSR1);
  }
  return 0;
}
