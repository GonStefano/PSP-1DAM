import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;
import java.util.Scanner;

public class TCPClientSocket1 {
    public static void main(String[] args) {
        Scanner tc = new Scanner(System.in);
        int puerto = 5555;
        //String host = "localhost";
        String host = "192.168.1.105"; //casa
        //String host = "192.168.204.105"; //clase
        //String host = "192.168.204.135"; //Profesor
        
        System.out.print("Introduce un numero: ");
        int num = tc.nextInt();
        try {
            Socket cliente1 = new Socket(host,puerto);
            DataOutputStream dos = new DataOutputStream(cliente1.getOutputStream());
            dos.writeUTF(String.valueOf(num));

            DataInputStream dis = new DataInputStream(cliente1.getInputStream());
            int factorial =Integer.parseInt(dis.readUTF());
            System.out.println("El factorial es "+factorial);

            dos.close();
            dis.close();
            cliente1.close();
        } catch (Exception e) {
            e.printStackTrace();  
        }
    }
}