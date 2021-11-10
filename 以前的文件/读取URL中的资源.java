
package test;

import java.net.URL;
import java.util.Scanner;




public class Test {
    
    public static void main(String[] args) {
        Scanner scanner;
        URL url;
        Thread readURL;
        Look look = new Look();
        System.out.println("输入url资源");
        scanner = new Scanner(System.in);
        String source = scanner.nextLine();
        try {
            url = new URL(source);
            look.setURL(url);
            readURL = new Thread(look);
            readURL.start();
        } catch (Exception e) {
        }
    }
    
}


package test;

import java.io.InputStream;
import java.net.URL;


public class Look implements Runnable {
    URL url;
    public void setURL(URL url){
        this.url=url;
    }
    public void run(){
        try {
            InputStream in = url.openStream();
            byte []b = new byte[1024];
            int n=-1;
            while((n=in.read(b))!=-1){
                String str = new String(b,0,n);
                System.out.println(str);
            }
        } catch (Exception e) {
        }
    }
}
