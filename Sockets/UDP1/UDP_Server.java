import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class UDP_Server{
    public static void main(String[] args) throws IOException {
        DatagramSocket socket = new DatagramSocket(5555);
        //InetAddress ip = InetAddress.getLocalHost();

        DatagramPacket recibo;

        byte[] bufer = new byte[1024];
        recibo = new DatagramPacket(bufer, bufer.length);
        socket.receive(recibo);

        String numero = new String(recibo.getData()).trim();
        System.out.println("Servidor recibe el numero de cliente 1 " + numero);

        InetAddress ipOrigenCliente1 = recibo.getAddress();
        int puertoCliente1 = recibo.getPort(); 

        byte[] enviado = new byte[1024];
        enviado = numero.getBytes();
        DatagramPacket enviadoC2 = new DatagramPacket(enviado,enviado.length,ipOrigenCliente1,5556);
        socket.send(enviadoC2);
        System.out.println("Enviado el numero a cliente 2");

        byte[] recibirC2 = new byte[1024];
        DatagramPacket recibidoc2 = new DatagramPacket(recibirC2, recibirC2.length);
        socket.receive(recibidoc2);
        String numeroc1 = new String(recibidoc2.getData()).trim();
        int factorial = Integer.parseInt(numeroc1);
        System.out.println("Recibe el factorial de cliente 2 "+factorial);

        byte[] enviarc1 = new byte[1024];
        enviarc1 = String.valueOf(factorial).getBytes();
        DatagramPacket enviadoC1 = new DatagramPacket(enviarc1, enviarc1.length,ipOrigenCliente1,puertoCliente1);
        socket.send(enviadoC1);
        System.out.println("Envia el factorial al cliente 1");

        socket.close();

    }

}

class UDP_Client1{
    public static void main(String[] args) throws IOException {
        Scanner tc = new Scanner(System.in);
        DatagramSocket clientSocket = new DatagramSocket();
        //InetAddress IPServidor = InetAddress.getLocalHost();
        InetAddress IPServidor = InetAddress.getByName("192.168.1.105"); //casa
        //InetAddress IPServidor = InetAddress.getByName("192.168.204.105"); //clase
        //InetAddress IPServidor = InetAddress.getByName("192.168.204.135"); //Profesor
        int puerto = 5555;

        System.out.print("Introduce un numero: ");
        int num = tc.nextInt();
    
        byte[] enviados = new byte[1024];
        enviados = String.valueOf(num).getBytes();

        DatagramPacket envio = new DatagramPacket(enviados, enviados.length, IPServidor, puerto);
        clientSocket.send(envio);
        System.out.println("Envia el numero al servidor");

        byte[] recibidos = new byte[1024];
        DatagramPacket recibido = new DatagramPacket(recibidos,recibidos.length);
        clientSocket.receive(recibido);
        System.out.println("Recibe el factorial de servidor");

        String numero = new String(recibido.getData()).trim();
        int factorial = Integer.parseInt(numero);
        System.out.println("El factorial de"+num+" es "+factorial);
        clientSocket.close();

    }
}

class UDP_Client2{
    public static void main(String[] args) throws IOException {
        DatagramSocket cliente2 = new DatagramSocket(5556);

        //InetAddress ipServidor = InetAddress.getLocalHost();
        InetAddress ipServidor = InetAddress.getByName("192.168.1.105"); //casa
        //InetAddress ipServidor = InetAddress.getByName("192.168.204.105"); //clase
        //InetAddress ipServidor = InetAddress.getByName("192.168.204.135"); //Profesor
        int puerto = 5555;

        byte[] recibir = new byte[1024];
        DatagramPacket recibido = new DatagramPacket(recibir, recibir.length);
        cliente2.receive(recibido);
        System.out.println("recibido numero para sacar factorial");
        String numero = new String(recibido.getData()).trim();
        System.out.println(numero);
        int num = Integer.parseInt(numero);

        int factorial = 1;
        for (int i = 1;i <= num; i++) {
            factorial *= i;
        }

        byte[] enviar = new byte[1024];
        enviar = String.valueOf(factorial).getBytes();
        DatagramPacket enviado = new DatagramPacket(enviar, enviar.length,ipServidor,puerto);
        cliente2.send(enviado);
        System.out.println("Enviado el factorial");

        cliente2.close();
    }
}