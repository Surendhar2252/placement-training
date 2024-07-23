import java.util.Scanner;

public class AbsolutePermutation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] perm = new int[n];
            boolean possible = true;
            for (int i = 0; i < n; i++) {
                if (i - k >= 0 && perm[i - k] == 0) perm[i] = i - k + 1;
                else if (i + k < n && perm[i + k] == 0) perm[i] = i + k + 1;
                else {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                for (int i : perm) System.out.print(i + " ");
                System.out.println();
            } else System.out.println(-1);
        }
    }
}
