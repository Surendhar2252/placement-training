import java.util.Scanner;

public class Candies {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] ratings = new int[n];
        int[] candies = new int[n];
        for (int i = 0; i < n; i++) ratings[i] = sc.nextInt();
        candies[0] = 1;
        for (int i = 1; i < n; i++) if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1; else candies[i] = 1;
        for (int i = n - 2; i >= 0; i--) if (ratings[i] > ratings[i + 1]) candies[i] = Math.max(candies[i], candies[i + 1] + 1);
        int totalCandies = 0;
        for (int candy : candies) totalCandies += candy;
        System.out.println(totalCandies);
    }
}
