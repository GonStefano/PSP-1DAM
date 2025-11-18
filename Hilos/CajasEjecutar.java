class Supermercado{
    private Caja[] caja;

    public Supermercado(int numcaja){
        caja = new Caja[numcaja];
        int num = 1;
        for(int i=0 ; i< caja.length ; i++){
            caja[i] = new Caja(num);
            num++;
        }
    }

    public synchronized Caja obtenerCaja(){
        while(true){
            for (int i=0 ; i< caja.length ; i++) {
                if (!caja[i].getOcupada()) {
                    return caja[i];
                }
            }
            

        }
    }
}

class Caja{
    private final int id;
    private boolean ocupada;
    Caja(int id){
        this.id = id;
        ocupada = false;
    }

    synchronized void atenderCliente(int clienteID){
        try {
            System.out.println("Cliente " + clienteID + " entrando en la caja...");

            ocupada =true;
            System.out.println("Caja " + id +" atendiendo al cliente " + clienteID);

            Thread.sleep(5000);

            System.out.println("Caja " + id + " termino con el cliente " + clienteID);
            ocupada = false;
        } catch (Exception e) {
            Thread.currentThread().interrupt();
            System.out.println("Cliente "+id+" interrumpido durante el cobro");
        }
    }

    public boolean getOcupada(){
        return ocupada;
    }
}


class Cliente extends Thread{
    private final int id;
    private final Supermercado sup;

    public Cliente(int id, Supermercado sup){
        this.id = id;
        this.sup = sup;
    }

    public void run(){
        System.out.println("Cliente "+id+" entra en la cola de espera.");

        Caja c= sup.obtenerCaja();

        c.atenderCliente(id);
        
    }
}


public class CajasEjecutar {
    public static void main(String[] args) throws InterruptedException {
        Supermercado sup = new Supermercado(2);
        int numClientes = 10;
        Thread clientes[] = new Thread[numClientes];
        for(int i=0 ; i<clientes.length ; i++){
            clientes[i] = new Cliente(i+1, sup);
            clientes[i].start();
        }

        for(int i=0 ; i<clientes.length ; i++){
            clientes[i].join();
        }
        System.out.println("Supermercado cerrado");
    }

}
