import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;

public class Array {
    public static void printArray(int[] arr) {
        for (int element : arr) {
            System.out.print(element + " ");
        }
        System.out.println();
    }

    public static int[] reserveArray(int[] arr) {
        int[] result = new int[arr.length];
        for (int i = 0, j = arr.length-1; i < arr.length; i++, j--) {
            result[j] = arr[i];
        }
        return result;
    }

    public static void dateTest(String[] args) {
        Date d = new Date();
        Date d2 = new Date(d.getTime()+60000);
        Date d3 = null;
        System.out.println(d);
        System.out.println(d2);
        System.out.println(d3);
        System.out.println(d.before(d2));
        System.out.println(d.after(new Date(2)));
        System.out.println((new Date(d.getTime())).clone());
        System.out.println(d.compareTo((Date) (new Date(d.getTime())).clone()));

        SimpleDateFormat ft = new SimpleDateFormat("E yyyy.MM.dd 'at' hh:mm:ss a zzz");

        System.out.println(ft.format(d));

        String str = String.format("Current Date/time : %tc", d);

        System.out.printf(str);
        System.out.printf("\n");
        System.out.println(str);

        str = String.format("%1$s %2$tB %2$td, %2$tY\n", "Due Day", d);
        System.out.printf(str);

        System.out.printf("%1$s %2$tB %2$td, %2$tY\n", "Due Day", d);

        ft = new SimpleDateFormat("yyyy/MM/dd");
        String input = args.length == 0 ? "2020/01/16" : args[0];
        System.out.print(input + " Parses as ");

        try {
            d = ft.parse(input);
            System.out.println(d);
        } catch (ParseException e) {
            System.out.println("Unparseable using " + input);
        }

        try {
            System.out.println(new Date() + "\n");
            Thread.sleep(1*1000);
            System.out.println(new Date() + "\n");
        } catch (Exception e) {
            System.out.println("Got an exception!");
        }

        try {
            long start = System.currentTimeMillis();
            System.out.println(new Date() + "\n");
            Thread.sleep(1*1000);
            System.out.println(new Date() + "\n");
            long end = System.currentTimeMillis();
            long diff = end - start;
            System.out.println("Difference is : " + diff);
        } catch (Exception e) {
            System.out.println("Got an exception!");
        }

        //System.out.println(d.compareTo());
    }

    public static void calendarTest(String[] args) {
        Calendar c = Calendar.getInstance();

        c.set(2000, 1-1, 1);
        System.out.println(c);
        c.set(Calendar.YEAR, 2020);
        System.out.println(c);
        c.add(Calendar.DATE, 15);
        c.add(Calendar.MONTH, 0);
        System.out.println("YEAR: " + c.get(Calendar.YEAR));
        System.out.println("MONTH: " + (c.get(Calendar.MONTH)+1));
        System.out.println("DATE: " + c.get(Calendar.DATE));
        System.out.println("HOUR: " + c.get(Calendar.HOUR_OF_DAY));
        System.out.println("MINUTE: " + c.get(Calendar.MINUTE));
        System.out.println("SECOND: " + c.get(Calendar.SECOND));
        System.out.println("WEEKDAY: " + c.get(Calendar.DAY_OF_WEEK));
        //c.set()

        GregorianCalendar greC = new GregorianCalendar();

        System.out.println(greC.isLeapYear(2020));

    }

    public static void main(String[] args) {
        int[] array = new int[10];
        printArray(new int[]{0, 1, 2,});
        Arrays.fill(array, 9);
        printArray(array);
        printArray(reserveArray(new int[]{0, 2, 4, 6, 8,}));
        int[] arrSort = {0, 12, 5, 6, 11, 3, 9, 7, 4, 8};
        Arrays.sort(arrSort);
        printArray(arrSort);
        System.out.println(Arrays.equals(arrSort, array));
        System.out.println(Arrays.equals(new int[]{9, 9, 9, 9, 9, 9, 9, 9, 9, 9, }, array));
        System.out.println(Arrays.binarySearch(arrSort, 10));
        System.out.println("<----------------------------------------------------------->");
        System.out.println("<   dateTest   >");
        dateTest(args);

        System.out.println("<----------------------------------------------------------->");
        System.out.println("<   calendarTest   >");
        calendarTest(args);
    }
}
