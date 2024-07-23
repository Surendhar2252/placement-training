#include <stdio.h>
#include <stdlib.h>

int dfs(int **grid, int i, int j, int n, int m) {
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) return 0;
    grid[i][j] = 0;
    int size = 1;
    for (int x = -1; x <= 1; x++)
        for (int y = -1; y <= 1; y++)
            size += dfs(grid, i + x, j + y, n, m);
    return size;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int **grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) scanf("%d", &grid[i][j]);
    }
    int max_size = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1)
                max_size = max(max_size, dfs(grid, i, j, n, m));
    printf("%d\n", max_size);
    for (int i = 0; i < n; i++) free(grid[i]);
    free(grid);
    return 0;
}
