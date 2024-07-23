import java.util.Scanner;

public class FrequencyCount {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        int[] count = new int[n+1];
        for (int i = 0; i < n; i++) count[sc.nextInt()]++;
        for (int i = 1; i <= n; i++) System.out.print(count[i] + " ");
    }
}
