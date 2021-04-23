import java.util.*;

public class ArrayListAndVectorTest {
    private static String name = "ArrayListAndVectorTest";
    private String date;

    public ArrayListAndVectorTest(String date) {
        this.date = date;
    }

    public void setDAte(String date) {
        this.date = date;
    }
    class Inner {
        private static final String name = "Inner";
        private String date;
        public Inner() {
            System.out.println(ArrayListAndVectorTest.this.date);
            System.out.println(ArrayListAndVectorTest.name);
        }

    }
    public static void main(String []args) {
        ArrayList<String> al= new ArrayList<>();

        al.add("WTF");

        for (String str : al) {
            System.out.println(str);
        }
        System.out.println(al.get(0));

        Vector<String> vs = new Vector<>();

        vs.add("I love you!");
        vs.add("I love you, too!");

        for (String str : vs) {
            System.out.println(str);
        }
        System.out.println(vs);

        LinkedList<String> lls = new LinkedList<>();
        lls.add("a");
        lls.add("a");

        ArrayListAndVectorTest out = new ArrayListAndVectorTest("20200415");
        ArrayListAndVectorTest.Inner in = new ArrayListAndVectorTest("202004ff5").new Inner();
        out.setDAte("20121221");
        ArrayListAndVectorTest.Inner in2 = out.new Inner();
        System.out.println(in);
        System.out.println(in2);

        People p = new Man().getWoman(9);
    }
}


class People{
    public People() {

    }
}

class Man{
    int b;
    public Man(){

    }

    public People getWoman(int a){
        class Woman extends People{   //局部内部类
            int age =0;

            public Woman() {
                System.out.println(a);
            }
        }
        return new Woman();
    }
}