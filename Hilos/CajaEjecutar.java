class CajaUnica{
    private final int id;
    private boolean ocupada;
    CajaUnica(int id){
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
    private final CajaUnica caja;

    public Cliente(int id, CajaUnica caja){
        this.id = id;
        this.caja = caja;
    }

    public void run(){
        System.out.println("Cliente "+id+" entra en la cola de espera.");
        caja.atenderCliente(id);
    }
}


public class CajaEjecutar {
    public static void main(String[] args) throws InterruptedException {
        CajaUnica caja = new CajaUnica(1);
        int clientes = 5;
        for(int i=0 ; i<clientes ; i++){
            Cliente c = new Cliente(i+1, caja);
            c.start();

            c.join();
        }
    }
}
