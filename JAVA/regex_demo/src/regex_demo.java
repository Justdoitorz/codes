import java.util.regex.Pattern;

public class regex_demo {
    public static void main(String[] args) {

        String pattern = "(.*)(\\d+)(.*)";
        Pattern r = Pattern.compile(pattern);
        System.out.println();

    }
}
