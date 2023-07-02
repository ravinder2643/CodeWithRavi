import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class Server {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(1234);
        System.out.println("Server is running and waiting for client connection...");

        while (true) {
            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected: " + clientSocket.getInetAddress().getHostAddress());

            Scanner sc = new Scanner(System.in);
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

            String inputLine;
            while ((inputLine = in.readLine()) != null) {
                System.out.println("Client : " + inputLine);
                // out.println("Server received your message: " + inputLine);
            }

            System.out.println("Enter your message : ");
            String str = sc.nextLine();

            out.println(str);

            in.close();
            out.close();
            clientSocket.close();
            System.out.println("Client disconnected.");
        }
    }
}
