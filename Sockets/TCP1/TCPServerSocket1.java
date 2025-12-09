import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class TCPServerSocket1 {
    public static void main(String[] args) {
        int puerto = 5555;
        try {
            ServerSocket Servidor = new ServerSocket(puerto);
            Socket cliente1 = Servidor.accept();
            System.out.println("Conexion con el servidor Exitoso Cliente 1.");
            InputStream entrada = cliente1.getInputStream();
            DataInputStream disc1 = new DataInputStream(entrada);
            String numero = disc1.readUTF();
            System.out.println("Recibiendo del cliente 1: "+numero);


            Socket cliente2 = Servidor.accept();
            System.out.println("El cliente2 se conecto con el servidor");
            OutputStream salida = cliente2.getOutputStream();
            DataOutputStream dos = new DataOutputStream(salida);
            dos.writeUTF(numero);

            System.out.println("Numero enviado al cliente 2");

            DataInputStream disc2 = new DataInputStream(cliente2.getInputStream());
            String factorial = disc2.readUTF();
            System.out.println("Recibir resultado del factorial: "+factorial+" Enviado por el cliente 2");
            
            

            OutputStream salidac1 = cliente1.getOutputStream();
            DataOutputStream dosc1 = new DataOutputStream(salidac1);
            dosc1.writeUTF(factorial);
            System.out.println("Enviando a cliente 1 el total del factorial del numero.");
            
            entrada.close();
            disc1.close();
            salidac1.close();
            dosc1.close();
            cliente1.close();
            
            salida.close();
            dos.close();
            disc2.close();

            Servidor.close();
        } catch (Exception e) {
            e.printStackTrace();  
        }
    }
}
