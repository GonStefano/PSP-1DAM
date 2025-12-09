import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

public class TCPClientSocket2 {
    public static void main(String[] args) {
        //String host = "localhost";
        String host = "192.168.1.105"; //casa
        //String host = "192.168.204.105"; //clase
        //String host = "192.168.204.135"; //Profesor

        int puerto = 5555;
        try {
            Socket cliente = new Socket(host,puerto);

            InputStream entrada = cliente.getInputStream();
            DataInputStream flujoEntrada = new DataInputStream(entrada);

            int num = Integer.parseInt(flujoEntrada.readUTF());
            System.out.println("Cliente 2 recibe el numero "+num+" del servidor");
            int factorial = 1;

            for (int i = 1; i <= num; i++) {
                factorial = factorial * i;
            }

            OutputStream salida = cliente.getOutputStream();
            DataOutputStream flujoSalida = new DataOutputStream(salida);
            flujoSalida.writeUTF(String.valueOf(factorial));
            System.out.println("Cliente 2 envia "+factorial+" al servidor");


            entrada.close();
            flujoEntrada.close();

            salida.close();
            flujoSalida.close();

            cliente.close();

        } catch (Exception e) {
            e.printStackTrace();  
        }

    }
}
