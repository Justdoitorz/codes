import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class ObjTest {
    public int age;
    public String name;

    public ObjTest(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void ObjMethodTest(ObjTest other) {
        other.name = "wtf";
        other.age = 0;
    }

    
}


public class enumC {
    static void methodModifyString(String str) {
        System.out.println(str.hashCode());
        str = "WTFf";
        System.out.println(Integer.parseInt(String.valueOf(str.hashCode()), 16));
    }
    public static void main(String []args) {
        Enumeration week;
        Vector dayNames = new Vector();
        dayNames.add("Sunday");
        dayNames.add("Monday");
        dayNames.add("Tuesday");
        dayNames.add("Wednesday");
        dayNames.add("Thurday");
        dayNames.add("Friday");
        dayNames.add("Saturday");
        week = dayNames.elements();

        while (week.hasMoreElements()) {
            System.out.println(week.nextElement());
        }

        BitSet bitSet = new BitSet(10);
        bitSet.set(1);
        bitSet.set(3);
        bitSet.set(5);
        bitSet.set(151);
        System.out.println(bitSet.toString());
        System.out.println(bitSet.get(151));


        Vector v = new Vector(3, 2);
        System.out.println("Initial size: " + v.size());
        System.out.println("Initial capacity: " +
                v.capacity());
        v.addElement(new Integer(1));
        v.addElement(new Integer(2));
        v.addElement(new Integer(3));
        v.addElement(new Integer(4));
        System.out.println("Capacity after four additions: " +
                v.capacity());

        v.addElement(new Double(5.45));
        System.out.println("Current capacity: " +
                v.capacity());
        v.addElement(new Double(6.08));
        v.addElement(new Integer(7));
        System.out.println("Current capacity: " +
                v.capacity());
        v.addElement(new Float(9.4));
        v.addElement(new Integer(10));
        System.out.println("Current capacity: " +
                v.capacity());
        v.addElement(new Integer(11));
        v.addElement(new Integer(12));
        System.out.println("First element: " +
                (Integer)v.firstElement());
        System.out.println("Last element: " +
                (Integer)v.lastElement());
        if(v.contains(new Integer(3)))
            System.out.println("Vector contains 3.");
        // enumerate the elements in the vector.
        Enumeration vEnum = v.elements();
        System.out.println("\nElements in vector:");
        while(vEnum.hasMoreElements())
            System.out.print(vEnum.nextElement() + " ");
        System.out.println();

        System.out.println(v.size());


        Properties capitals = new Properties();
        Set states;
        String str;

        capitals.put("Illinois", "Springfield");
        capitals.put("Missouri", "Jefferson City");
        capitals.put("Washington", "Olympia");
        capitals.put("California", "Sacramento");
        capitals.put("Indiana", "Indianapolis");

        // Show all states and capitals in hashtable.
        states = capitals.keySet(); // get set-view of keys
        Iterator itr = states.iterator();
        while(itr.hasNext()) {
            str = (String) itr.next();
            System.out.println("The capital of " +
                    str + " is " + capitals.getProperty(str) + ".");
        }
        System.out.println();

        // look for state not in list -- specify default
        str = capitals.getProperty("Indiana", "Not Found");
        System.out.println("The capital of Florida is "
                + str + ".");





        String original = "    1";
        String []strArr = original.split(" ", 0);
        for (String lstr : strArr) {
            System.out.println("...:" + lstr);
        }
        System.out.println(String.join(" ", strArr));


        BigInteger bigInteger = new BigInteger("10");
        BigInteger big2 = new BigInteger("20");
        bigInteger = bigInteger.multiply(big2);
        bigInteger = bigInteger.nextProbablePrime();
        System.out.println(bigInteger);

        Map<Integer, Integer> mp = new HashMap<>();

        System.out.println("Hello, Xiao brother!");

        String []strArr2 = new String[]{"banana", "apple", "peer"};

        Arrays.sort(strArr2);

        String fuck = "fucf";
        System.out.println(fuck.hashCode());
        // char *fuck = "fuck";
        methodModifyString(fuck);
        //func(fuck) {fuck2 = "wtf";}
        System.out.println(fuck);
        //printf("%s\n", fuck);

        ObjTest a = new ObjTest("SB", 19);
        ObjTest b = new ObjTest("SD", 16);

        a.ObjMethodTest(b);
        System.out.println(b.name);
        System.out.println(b.age);



        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i+j == 9) {
                    System.out.print(' ');
                } else {
                    System.out.print('*');
                }
            }
            System.out.println();
        }

        System.out.println("------");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i==j) {
                    System.out.print(' ');
                } else {
                    System.out.print('*');
                }
            }
            System.out.println();
        }

        System.out.println("------");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i==j || i+j == 9) {
                    System.out.print(' ');
                } else {
                    System.out.print('*');
                }
            }
            System.out.println();
        }


        System.out.println("------");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == 2) {
                    System.out.print(' ');
                } else {
                    System.out.print('*');
                }
            }
            System.out.println();
        }
    }
}
