import java.io.*;
import java.util.Scanner;

public class BRRead {
    public static void main(String[] args) throws IOException {
        char c;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Enter characters, \" 'q' to quit");

        /*
        do {
            c = (char)br.read();
            System.out.print(c);
        } while (c != 'q');

        String str;

        do {
            str = br.readLine();
            System.out.println(str);
        } while (!str.equals("end"));


         */

        System.out.write('A');
        System.out.write('\n');

        InputStream f = new FileInputStream("F:/Code/JAVA/IO/untitled/src/BRRead.java");
        byte[] buf = new byte[1];
        byte b;
        b = (byte)f.read();
        System.out.println(b);
        System.out.println((char)f.read());

        while (f.read(buf) != -1) {
            System.out.print(new String(buf));
        }

        f.close();

        System.out.println("------------------");

        Scanner s = new Scanner(System.in);

//        if (s.hasNext()) {
//            String instr = s.next();
//            System.out.println(instr);
//        }
//
////        if (s.hasNext()) {
////            String instr = s.next();
////            System.out.println(instr);
////        }

        System.out.println("hello");

        
    }

}
