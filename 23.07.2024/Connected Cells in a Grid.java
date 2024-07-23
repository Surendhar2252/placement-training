import java.util.Scanner;

public class ConnectedCells {
    static int dfs(int[][] grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        int size = 1;
        for (int x = -1; x <= 1; x++) for (int y = -1; y <= 1; y++) size += dfs(grid, i + x, j + y);
        return size;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        int[][] grid = new int[n][m];
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) grid[i][j] = sc.nextInt();
        int maxArea = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) maxArea = Math.max(maxArea, dfs(grid, i, j));
        System.out.println(maxArea);
    }
}
