/* El programa muestra cómo capturar una señal del sistema (en este caso SIGINT) 
   y cómo asignarle un manejador personalizado -> función que se ejecuta cuando llega la señal*/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include <time.h>

/*
  fun_signal es la función manejadora (handler) de la señal.
   - El parámetro signum recibe el número de la señal (en este caso, SIGINT = 2).
   - Cuando el usuario pulsa Ctrl+C, en lugar de que el programa termine inmediatamente (comportamiento por defecto), se ejecuta esta función
  */
pid_t pid;

void fun_signal(int signum){
  time_t final = time(NULL);
  struct tm *t = localtime(&final);
    printf("Fin del proceso %d: %02d/%02d/%04d %02d:%02d:%02d\n",
        pid,
        t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
        t->tm_hour, t->tm_min, t->tm_sec);
  //signal(SIGINT,SIG_DFL);   // Se "re-arma" la señal con su acción por defecto
}


int main(){
  pid = getpid();
  time_t inicio = time(NULL);
  struct tm *t = localtime(&inicio);

    printf("Inicio del proceso %d: %02d/%02d/%04d %02d:%02d:%02d\n",
        pid,
        t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
        t->tm_hour, t->tm_min, t->tm_sec);
  signal(SIGINT,fun_signal); // Esta línea registra la función manejadora para la señal SIGINT. A partir de aquí, si se pulsa Ctrl+C, se ejecutará fun_signal()
  pause();

  
  return 0;
}
