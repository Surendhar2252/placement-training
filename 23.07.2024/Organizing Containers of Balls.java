import java.util.Scanner;

public class OrganizingContainers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] matrix = new int[n][n];
        int[] rowSum = new int[n], colSum = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = sc.nextInt();
                rowSum[i] += matrix[i][j];
                colSum[j] += matrix[i][j];
            }
        }
        java.util.Arrays.sort(rowSum);
        java.util.Arrays.sort(colSum);
        System.out.println(java.util.Arrays.equals(rowSum, colSum) ? "Possible" : "Impossible");
    }
}
