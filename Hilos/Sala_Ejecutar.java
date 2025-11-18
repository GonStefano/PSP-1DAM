class Salon{
    private int numero=0;
    private int aforoMax;

    public Salon(int aforoMax){
        this.aforoMax = aforoMax;
    }

    public synchronized void entrar(int n){
        
        while (numero==aforoMax) {
            try {
                wait();
            } catch (InterruptedException e) {
            }
        }

        numero++;
        System.out.println("Cliente "+n+" entra a la sala de entrenamiento");

    }


    public synchronized void salir(int n){

        numero--;
        System.out.println("Cliente "+n+" saliendo de la sala");
        notifyAll();
    }
}

class Cliente extends Thread{
    int id;
    Salon c;

    public Cliente(Salon c,int id){
        this.id = id;
        this.c = c;
    }

    public void run(){
        c.entrar(id);
        try {
            Thread.sleep((long) (Math.random() * 3000 + 1000));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        c.salir(id);
    }
}

public class Sala_Ejecutar {
    public static void main(String[] args) {
        Thread clientes[] = new Thread[20];
        Salon c = new Salon(5);

        for (int i = 0; i < clientes.length; i++) {
            clientes[i] = new Cliente(c, i+1);

            clientes[i].start();
        }
    }
}
