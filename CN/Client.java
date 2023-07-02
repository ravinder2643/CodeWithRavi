import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws IOException {

        String hostName = "localhost";
        int portNumber = 1234;

        try (
                Socket socket = new Socket(hostName, portNumber);
                PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
                BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in))) 
            System.out.println("Connected to server: " + hostName + ":" + portNumber);


            System.out.println("Enter message for sender : ");
            String userInput;
            while ((userInput = stdIn.readLine()) != null) {
                out.println(userInput);
                String serverResponse = in.readLine();
                // System.out.println("Server response: " + serverResponse);
            }

            String inputLine;
            while ((inputLine = in.readLine()) != null) {
                System.out.println("Server : " + inputLine);
                // out.println("Server received your message: " + inputLine);
            }

        }catch(

    UnknownHostException e)
    {
        System.err.println("Unknown host: " + hostName);
        System.exit(1);
    }catch(
    IOException e)
    {
        System.err.println("I/O error occurred while connecting to " + hostName + ":" + portNumber);
        System.exit(1);
    }
}}
