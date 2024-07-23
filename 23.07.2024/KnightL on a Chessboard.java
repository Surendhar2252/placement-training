import java.util.*;

public class KnightOnChessboard {
    static int minMoves(int n, int startX, int startY, int endX, int endY) {
        int[] dx = {1, 1, -1, -1, 2, 2, -2, -2};
        int[] dy = {2, -2, 2, -2, 1, -1, 1, -1};
        boolean[][] visited = new boolean[n][n];
        int[][] dist = new int[n][n];
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{startX, startY});
        visited[startX][startY] = true;
        dist[startX][startY] = 0;
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int x = cell[0], y = cell[1];
            if (x == endX && y == endY) return dist[x][y];
            for (int i = 0; i < 8; i++) {
                int newX = x + dx[i], newY = y + dy[i];
                if (newX >= 0 && newY >= 0 && newX < n && newY < n && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    dist[newX][newY] = dist[x][y] + 1;
                    queue.add(new int[]{newX, newY});
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int startX = sc.nextInt(), startY = sc.nextInt();
        int endX = sc.nextInt(), endY = sc.nextInt();
        System.out.println(minMoves(n, startX, startY, endX, endY));
    }
}
