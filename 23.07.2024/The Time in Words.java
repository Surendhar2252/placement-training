import java.util.Scanner;

public class TimeInWords {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] numToWords = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", 
                              "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", 
                              "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", 
                              "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", 
                              "twenty nine"};
        int h = sc.nextInt(), m = sc.nextInt();
        if (m == 0) System.out.println(numToWords[h] + " o' clock");
        else if (m == 15) System.out.println("quarter past " + numToWords[h]);
        else if (m == 30) System.out.println("half past " + numToWords[h]);
        else if (m == 45) System.out.println("quarter to " + numToWords[h + 1]);
        else if (m < 30) System.out.println(numToWords[m] + " minute" + (m > 1 ? "s" : "") + " past " + numToWords[h]);
        else System.out.println(numToWords[60 - m] + " minute" + (60 - m > 1 ? "s" : "") + " to " + numToWords[h + 1]);
    }
}
