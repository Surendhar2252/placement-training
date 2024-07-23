import java.util.Arrays;
import java.util.Scanner;

public class FraudulentActivity {
    static int findMedian(int[] expenditure, int d) {
        int[] sorted = Arrays.copyOf(expenditure, d);
        Arrays.sort(sorted);
        if (d % 2 == 1) return sorted[d / 2];
        return (sorted[d / 2] + sorted[d / 2 - 1]) / 2;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), d = sc.nextInt();
        int[] expenditure = new int[n];
        for (int i = 0; i < n; i++) expenditure[i] = sc.nextInt();
        int notifications = 0;
        for (int i = d; i < n; i++) {
            int median = findMedian(Arrays.copyOfRange(expenditure, i - d, i), d);
            if (expenditure[i] >= 2 * median) notifications++;
        }
        System.out.println(notifications);
    }
}
