import java.nio.charset.StandardCharsets;

public class char_l {
    public String getName() {
        return "char_l";
    }
    public  static Character test(char ch) {
        Character c = ch;
        return c;
    }
    public static void main(String []args) {
        char ch = 'a';
        char unich = '\u039a';

        System.out.println(ch);
        System.out.println(unich);



        Character Ch = new Character(ch);
        Character x = 'x';
        char c = test('f');


        Character chobj = new Character('O');

        System.out.println(Character.isLetter('A'));
        System.out.println(Character.isLetter(65));

        System.out.println(Character.isDigit('9'));
        System.out.println(Character.isDigit(48));

        System.out.println("Whitespace");
        System.out.println(Character.isWhitespace(9));
        System.out.println(Character.isWhitespace('\t'));
        for (int i = 0; i < 33; i++) {
            System.out.println(i + ":" + Character.isWhitespace(i) + " ch:" + (char)i);
        }

        System.out.println(Character.isUpperCase('c'));
        System.out.println(Character.isUpperCase('C'));

        System.out.println(Character.isLowerCase(97));
        System.out.println(Character.isLowerCase(65));

        System.out.println(Character.toLowerCase(97));
        System.out.println(Character.toLowerCase(65));

        System.out.println(Character.toUpperCase('a'));
        System.out.println(Character.toUpperCase('A'));

        System.out.println(chobj.toString().length());
        System.out.println(Character.toString('a'));

        System.out.println("WTF".length());
        String str = new String("WTF");
        System.out.println(str);
        char[] helloArr = {'H', 'e', 'l', 'l', 'o'};
        char[] other = helloArr;
        System.out.println(other);
        other[0] = 'h';
        System.out.println(other);
        System.out.println(helloArr);

        String helloToString = new String(helloArr);

        System.out.println(str.concat("fuck"));
        System.out.println(helloToString + "World");

        String stradd = "Woaini" + "money";

        System.out.println(stradd);

        str = String.format("woainidolemifasolaxi %d, %dwoaini",  1, 2);

        System.out.println(str);
        System.out.println(str.charAt(1));
        System.out.println(str.compareTo("woainf"));
        System.out.println(str.compareToIgnoreCase("WOAINIDOLEMIFASOLAXI 1, 2"));
        System.out.println(str.concat("fuck"));
        System.out.println(str.contentEquals("woai"));
        System.out.println("woai".contentEquals("woai"));
        System.out.println(String.copyValueOf(helloArr));
        System.out.println(String.copyValueOf(helloArr, 2, 3));
        System.out.println(String.copyValueOf(helloArr, 2, 3).endsWith("lo"));
        System.out.println(helloToString.equals("hello"));
        System.out.println(str.equalsIgnoreCase(str.toUpperCase()));
        byte[] barr = helloToString.getBytes();
        System.out.println(barr);
        System.out.println(helloArr);

        try {
            byte[] bcarr = helloToString.getBytes("big5");
        }catch (Exception e) {
            e.printStackTrace();
        }

        char[] dest = {'0', 1, 2, 3, 5};
        str.getChars(6, 9, dest, 2);

        System.out.println(str.hashCode());
        System.out.println(str.indexOf( 'i'));
        System.out.println(str.indexOf('i', 4));
        System.out.println(str.indexOf("ini"));
        System.out.println(str.indexOf("ini", 5));
        System.out.println(str.intern());

        System.out.println(str.lastIndexOf('i'));
        System.out.println(str.lastIndexOf('i', 4));
        System.out.println(str.lastIndexOf("ini"));
        System.out.println(str.lastIndexOf("ini", 5));

        System.out.println(str.length());
        System.out.println(str.matches("(.*w?i)"));
        System.out.println(str.replace("ini", "InI"));
        System.out.println(str.replaceAll(".*ini", "InI"));
        System.out.println(str.replaceFirst("ini", "InI"));

    }
}