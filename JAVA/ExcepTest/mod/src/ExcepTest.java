import java.rmi.RemoteException;

public class ExcepTest {
    public static void main(String []args) throws RemoteException {
        try {
            int[] a = new int[2];
            System.out.println("Access element three" + a[3]);
        } catch(ArrayIndexOutOfBoundsException e) {
            System.out.println("Exception throw: " + e);
        } catch(ArithmeticException e) {
            System.out.println("Exception throw: " + e);
        } finally {
            Integer i = (int) 1.1;
            System.out.println(i);
        }

        System.out.println("Out of the block " + 0);

    }
}
