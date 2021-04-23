public class Hello {
    public static void main(String[] args) {
        int a = -4;
        System.out.println("Hello Java");
        Hello ob = new Hello();

        boolean result = ob instanceof Hello;
        System.out.println(result);
        System.out.println("a = " + (a>>2));
        System.out.println("a = " + (byte)(255));
        System.out.println("a = " + (int)(char)(255));
        System.out.println("a = " + (short)(255));
        System.out.println("a = " + (int)(255));

        int []numbers = {10, 20, 30, 40, 50};
        for (int x : numbers) {
            System.out.println(x);
        }

        for (String s : args) {
            System.out.println(s);
        }
        Integer x = 1024;
        x >>= 2;
        Number n = new Double('A');
        System.out.println(n.intValue());
        System.out.println(n instanceof  Number);

        System.out.println(0.0/0);
        System.out.println(Math.sin(Math.PI/2));
        System.out.println(Math.asin(1));
        System.out.println(Math.sin(Math.PI/6));
        System.out.println(Math.cos(0));
        System.out.println(Math.tan(Math.PI/4));
        System.out.println(Math.tan(Math.PI/3));

        System.out.println(x.doubleValue());
        System.out.println(x.compareTo(254));
        System.out.println(x.equals(256));
        Short s;
//        System.out.println(s.intValue().valueOf(1));
        Integer xx = x.valueOf("444", 16);
        System.out.println(x.valueOf("444",  16).toString());

    }
}
