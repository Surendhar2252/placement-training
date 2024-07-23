import java.util.Scanner;

public class SpecialPalindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                String sub = s.substring(i, j + 1);
                if (isSpecialPalindrome(sub)) count++;
            }
        }
        System.out.println(count);
    }

    private static boolean isSpecialPalindrome(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) freq[c - 'a']++;
        int oddCount = 0;
        for (int f : freq) if (f % 2 != 0) oddCount++;
        return oddCount <= 1;
    }
}
