class CuentaBancaria{
    int saldo = 1000;

    void sacarDinero(String nombre, int importe){
        try{
            if (saldo>=importe) {
                saldo = saldo - importe;
            System.out.println(nombre + " saco de la cuenta " + importe);
            }else{
                System.out.println(nombre + " no puede sacar =" + importe + " -> NO HAY SALDO SUFICIENTE");
            }
            
            System.out.println("Saldo actual cuenta: " + saldo);
            Thread.sleep(1000);
        }catch(InterruptedException e){
            e.printStackTrace();
        }
    }

    void ingresarDinero(String nombre, int importe){
        try{
            
            saldo = saldo +importe;
            System.out.println(nombre + " ingresó en la cuenta " + importe);
            System.out.println("Saldo actual cuenta: " + saldo);

            Thread.sleep(1000);
        }catch(InterruptedException e){
            e.printStackTrace();
        }

    }
}
class HiloSacarDinero extends Thread{
    private CuentaBancaria cuenta;
    private String nombre;
    private int cantidad;

    HiloSacarDinero(CuentaBancaria micuenta, String nombre, int cantidad){
        cuenta = micuenta;
        this.nombre = nombre;
        this.cantidad = cantidad;
    }

    public void run(){
        cuenta.sacarDinero(nombre, cantidad);

    }
}

class HiloIngresarDinero extends Thread{
    private CuentaBancaria cuenta;
    private String nombre;
    private int cantidad;

    HiloIngresarDinero(CuentaBancaria micuenta, String nombre, int cantidad){
        cuenta = micuenta;
        this.nombre = nombre;
        this.cantidad = cantidad;
    }

    public void run(){
        cuenta.ingresarDinero(nombre, cantidad);
    }
}


public class CajeroAutomaticoEjecutar {
    public static void main(String[] args) throws InterruptedException {
        CuentaBancaria cuenta1 = new CuentaBancaria();
        Thread pa = new Thread(new HiloIngresarDinero(cuenta1,"Padre",200));
        Thread ma = new Thread(new HiloSacarDinero(cuenta1,"Madre", 800));
        Thread h1 = new Thread(new HiloIngresarDinero(cuenta1,"Hijo1", 300));
        Thread h2 = new Thread(new HiloSacarDinero(cuenta1,"Hijo2", 800));
        Thread abu = new Thread(new HiloSacarDinero(cuenta1,"Abuelo", 600));

        pa.start();
        pa.join();
        ma.start();
        ma.join();
        h1.start();
        h1.join();
        h2.start();
        h2.join();
        abu.start();
    }
}
