import java.util.Scanner;

public class MaxArraySum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
        int incl = arr[0], excl = 0;
        for (int i = 1; i < n; i++) {
            int temp = incl;
            incl = Math.max(incl, excl + arr[i]);
            excl = temp;
        }
        System.out.println(incl);
    }
}
