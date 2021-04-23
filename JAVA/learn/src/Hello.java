import javafx.beans.binding.NumberBinding;

public class Hello {
    public static void main(String []args) {
        System.out.println("Hello Java");
        Integer num = 1024;
        //xxxValue   return base xxx type value
        System.out.println(num.doubleValue());
        //compareTo:   > arg return 1, < arg return -1, == arg return 0
        System.out.println(num.compareTo(222));
        //equals :  == return true, otherwise return false
        System.out.println(num.equals(1024));
        //valueOf:  return a Integer obj
        System.out.println(Integer.valueOf(99));

        //toString : return String
        System.out.println(num.toString());
        System.out.println(Integer.toString(1234));

        //parseInt: parse to int
        System.out.println(Integer.parseInt("-1024"));
        System.out.println(Integer.parseInt("122", 3));

        //abs: class Math static method
        System.out.println(Math.abs(-2));
        System.out.println(Math.abs((long)-2));
        System.out.println(Math.abs(-2.0));
        System.out.println(Math.abs((float)-2.0));


        //ceil: Up
        System.out.println(Math.ceil(99.2));//100
        //floor: Down
        System.out.println(Math.floor(99.2));//99

        //rint: how to work?
        System.out.println(Math.rint(99.499999999));
        //round
        System.out.println(Math.round((float)1.23456));
        //min:
        System.out.println(Math.min(-999, 666));
        System.out.println(Math.min(-999.0, 666));

        //max:
        System.out.println(Math.max(-999, 666));
        //exp : e^arg
        System.out.println(Math.exp(1));
        //log : log _e arg
        System.out.println(Math.log(Math.E));
        //pow: a^b
        System.out.println(Math.pow(3, 3));
        //sqrt:
        System.out.println(Math.sqrt(9));

        System.out.println(Math.sin(Math.PI/2));
        System.out.println(Math.cos(Math.PI));
        System.out.println(Math.tan(Math.PI/4));

        //PI = 3.14... = 90°
        System.out.println(Math.asin(1));
        System.out.println(Math.acos(1));
        System.out.println(Math.atan(1));
        System.out.println(Math.atan2(1, 1));

        System.out.println(Math.toDegrees(Math.PI));
        System.out.println(Math.toRadians(90));

        System.out.println(Math.random());
    }
}
