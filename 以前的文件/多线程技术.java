
package test;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;


public class Test {
    
    public static void main(String[] args) throws UnknownHostException {
        Scanner scanner = new Scanner(System.in);
        Socket mysocket=null;
        DataInputStream in=null;
        DataOutputStream out=null;
        Thread readData;
        Read read=null;
        try{
            mysocket=new Socket();
            read = new Read();
            readData = new Thread(read);
            System.out.println("输入服务器的IP:");
            String IP = scanner.nextLine();
            System.out.println("输入端口号：");
            int port = scanner.nextInt();
            if(mysocket.isConnected()){}
            else{
                InetAddress address=InetAddress.getByName(IP);
                InetSocketAddress socketAddress=new InetSocketAddress(address,port);
                mysocket.connect(socketAddress);
                in = new DataInputStream(mysocket.getInputStream());
                out = new DataOutputStream(mysocket.getOutputStream());
                read.setDataInputStream(in);
                readData.start();
            }
        }
        catch(Exception e){System.out.println("服务器已断开"+e);}
        System.out.println("输入圆的半径（放弃请输入N）：");
        while(scanner.hasNext()){
            double radius=0;
            try {
                radius = scanner.nextDouble();
            } catch (Exception e) {
                System.exit(0);
            }
            try {
                out.writeDouble(radius);
            } catch (Exception e) {
            }
        }
    }
    
}


package test;

import java.io.DataInputStream;


public class Read implements Runnable {
    DataInputStream in;
    public void setDataInputStream(DataInputStream in){
        this.in = in;
    }
    public void run(){
        double result = 0;
        while(true){
            try {
                result = in.readDouble();
                System.out.println("圆的面积："+result);
                System.out.println("输入圆的半径（放弃输入N）:");
            } catch (Exception e) {
                System.out.println("与服务器已断开"+e);
                break;
            }
        }
    }
}



package test;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.ServerSocket;
import java.net.Socket;


public class Server {
    public static void main(String[] args) {
        ServerSocket server = null;
        ServerThread thread;
        Socket you = null;
        while(true){
            try {
                server = new ServerSocket(2010);
            } catch (Exception e) {
                System.out.println("正在监听");
            }
            try {
                System.out.println("等待客户呼叫");
                you = server.accept();
                System.out.println("客户的地址："+you.getInetAddress());
            } catch (Exception e) {
                System.out.println("正在等待客户");
            }
            if(you!=null){
                new ServerThread(you).start();
            }
        }
    }
}
class ServerThread extends Thread{
    Socket socket;
    DataOutputStream out = null;
    DataInputStream in = null;
    String s = null;
    ServerThread(Socket t){
        socket = t;
        try {
            out = new DataOutputStream(socket.getOutputStream());
            in = new DataInputStream(socket.getInputStream());
        } catch (Exception e) {
        }
    }
    public void run(){
        while(true){
            try {
                double r = in.readDouble();
                double area=Math.PI*r*r;
                out.writeDouble(area);
            } catch (Exception e) {
                System.out.println("客户离开");
                return;
            }
        }
    }
}
