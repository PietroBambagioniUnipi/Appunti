import java.io.*;
import java.net.*;

public class udpclient {
    public static void main(String args[]) throws Exception {
        BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
        DatagramSocket clientSocket = new DatagramSocket();
        
        // L'indirizzo IPv6 del tuo nodo sensore (controlla su Cooja o via browser)
        InetAddress IPAddress = InetAddress.getByName("fd00::202:2:2:2"); 
        
        byte[] sendData;
        byte[] receiveData = new byte[1024];
        
        System.out.println("Scrivi un messaggio:");
        String sentence = inFromUser.readLine();
        sendData = sentence.getBytes();
        
        // Invia il pacchetto sulla porta 5678
        DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 5678);
        clientSocket.send(sendPacket);
        
        // Ricevi la risposta
        DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
        clientSocket.receive(receivePacket);
        String modifiedSentence = new String(receivePacket.getData());
        System.out.println("Risposta dal sensore: " + modifiedSentence.trim());
        
        clientSocket.close();
    }
}
