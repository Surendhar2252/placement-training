import java.util.Scanner;

public class StringReduction {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        while (true) {
            StringBuilder sb = new StringBuilder();
            boolean reduced = false;
            for (int i = 0; i < s.length(); i++) {
                if (i < s.length() - 1 && s.charAt(i) == s.charAt(i + 1)) {
                    i++;
                    reduced = true;
                } else sb.append(s.charAt(i));
            }
            s = sb.toString();
            if (!reduced) break;
        }
        System.out.println(s.length());
    }
}
