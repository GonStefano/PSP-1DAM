class HiloSumasRestas implements Runnable{
    private int numero=1000;

    public HiloSumasRestas(int numVeces, String operacion){
        if (operacion.equals("+")) {
            incrementar(numVeces);
        }else if (operacion.equals("-")) {
            decrementar(numVeces);
        }
    }

    public int incrementar(int numveces){
        numero = numero + numveces;
        return numero;
    }

    public int decrementar(int numveces){
        numero = numero - numveces;
        return numero;
    }
    public void run(){
        System.out.println(Thread.currentThread().getName() + " el resultado es: " + numero);
    }
}

public class HiloSumasRestasEjecutar{
    public static void main(String[] args) throws InterruptedException {
        Thread t1 = new Thread(new HiloSumasRestas(100,"+"),"HiloSuma1");
        Thread t2 = new Thread(new HiloSumasRestas(100,"-"),"HiloResta2");
        Thread t3 = new Thread(new HiloSumasRestas(1,"+"),"HiloSuma3");
        Thread t4 = new Thread(new HiloSumasRestas(1,"-"),"HiloResta4");

        t1.start();
        t1.join();
        t2.start();
        t2.join();
        t3.start();
        t3.join();
        t4.start();
    }

}

