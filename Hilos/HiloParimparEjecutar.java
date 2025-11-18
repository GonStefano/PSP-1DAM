class HiloParimpar implements Runnable{
    private int tipo;
    public HiloParimpar(int tipo){
        this.tipo = tipo;
    }

    public void run() {
        
        if (tipo == 1) {
            for(int i=2 ; i<=100 ; i+=2){
            System.out.println(Thread.currentThread().getName() + " generando numero par " + i);

            }
        }else{
            for(int i=101 ; i<=200 ; i+=2){
                System.out.println(Thread.currentThread().getName() + " generando numero par " + i);
            }
        }
    }
    
}
public class HiloParimparEjecutar{
    public static void main(String[] args) throws InterruptedException {
        Thread t1 = new Thread(new HiloParimpar(1),"Hilo 1");
        Thread t2 = new Thread(new HiloParimpar(2),"Hilo 2");
        t2.start();
        t2.join();
        t1.start();
        t1.join();

    }

}
