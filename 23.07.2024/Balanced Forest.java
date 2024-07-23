import java.util.Scanner;

public class BalancedForest {
    static int[] dfs(int node, int parent, int[] arr, int[][] adjList, int[] subTreeSum) {
        subTreeSum[node] = arr[node];
        for (int child : adjList[node]) if (child != parent) {
            subTreeSum = dfs(child, node, arr, adjList, subTreeSum);
            subTreeSum[node] += subTreeSum[child];
        }
        return subTreeSum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
        int[][] adjList = new int[n][];
        for (int i = 0; i < n; i++) adjList[i] = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
            adjList[u][i] = v;
            adjList[v][i] = u;
        }
        int[] subTreeSum = new int[n];
        subTreeSum = dfs(0, -1, arr, adjList, subTreeSum);
        System.out.println("Not Implemented");
    }
}
