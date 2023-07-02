import java.io.*;
import java.net.*;

public class FileClient {
    public static void main(String[] args) {
        String serverAddress = "localhost"; // Server address
        int serverPort = 1234; // Server port number
        String fileName = "file.txt"; // File name to download

        try (Socket socket = new Socket(serverAddress, serverPort)) {
            System.out.println("Connected to server: " + serverAddress + ":" + serverPort);

            // Create input/output streams for the socket
            OutputStream outputStream = socket.getOutputStream();
            DataOutputStream dataOutputStream = new DataOutputStream(outputStream);

            // Send the file name to the server
            dataOutputStream.writeUTF(fileName);
            dataOutputStream.flush();

            // Create input stream to receive file data from the server
            InputStream inputStream = socket.getInputStream();
            FileOutputStream fileOutputStream = new FileOutputStream(fileName);
            BufferedOutputStream bufferedOutputStream = new BufferedOutputStream(fileOutputStream);

            // Receive and write the file data to disk
            byte[] buffer = new byte[4096];
            int bytesRead;
            while ((bytesRead = inputStream.read(buffer)) != -1) {
                bufferedOutputStream.write(buffer, 0, bytesRead);
            }

            // Close streams and socket
            bufferedOutputStream.flush();
            bufferedOutputStream.close();
            inputStream.close();
            dataOutputStream.close();
            socket.close();

            System.out.println("File downloaded: " + fileName);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
//
//
//
//
//
//
//

//
//
import java.io.*;
import java.net.*;

public class FileServer {
    public static void main(String[] args) {
        int port = 1234; // Port number to listen on

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("File Server started. Listening on port " + port);

            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Client connected: " + clientSocket.getInetAddress().getHostAddress());

                // Start a new thread to handle the client connection
                Thread thread = new Thread(new ClientHandler(clientSocket));
                thread.start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static class ClientHandler implements Runnable {
        private final Socket clientSocket;

        public ClientHandler(Socket socket) {
            this.clientSocket = socket;
        }

        @Override
        public void run() {
            try {
                // Create input/output streams for the client socket
                InputStream inputStream = clientSocket.getInputStream();
                DataInputStream dataInputStream = new DataInputStream(inputStream);

                String fileName = dataInputStream.readUTF(); // Read the file name sent by the client

                // Open the file for reading
                File file = new File(fileName);
                FileInputStream fileInputStream = new FileInputStream(file);
                BufferedInputStream bufferedInputStream = new BufferedInputStream(fileInputStream);

                // Create output stream to send the file data to the client
                OutputStream outputStream = clientSocket.getOutputStream();
                DataOutputStream dataOutputStream = new DataOutputStream(outputStream);

                // Send the file data to the client
                byte[] buffer = new byte[4096];
                int bytesRead;
                while ((bytesRead = bufferedInputStream.read(buffer)) != -1) {
                    dataOutputStream.write(buffer, 0, bytesRead);
                }

                // Close streams and sockets
                bufferedInputStream.close();
                dataOutputStream.flush();
                dataOutputStream.close();
                inputStream.close();
                clientSocket.close();

                System.out.println("File sent: " + fileName);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
