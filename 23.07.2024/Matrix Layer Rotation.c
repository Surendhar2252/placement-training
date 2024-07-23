#include <stdio.h>

void rotateLayer(int **matrix, int m, int n, int layer, int rotations) {
    int size = 2 * (m + n - 2 - 4 * layer);
    int temp[size], idx = 0;
    for (int i = layer; i < n - layer; i++) temp[idx++] = matrix[layer][i];
    for (int i = layer + 1; i < m - layer; i++) temp[idx++] = matrix[i][n - layer - 1];
    for (int i = n - layer - 2; i >= layer; i--) temp[idx++] = matrix[m - layer - 1][i];
    for (int i = m - layer - 2; i > layer; i--) temp[idx++] = matrix[i][layer];
    
    int start = rotations % size;
    idx = 0;
    for (int i = layer; i < n - layer; i++) matrix[layer][i] = temp[(start + idx++) % size];
    for (int i = layer + 1; i < m - layer; i++) matrix[i][n - layer - 1] = temp[(start + idx++) % size];
    for (int i = n - layer - 2; i >= layer; i--) matrix[m - layer - 1][i] = temp[(start + idx++) % size];
    for (int i = m - layer - 2; i > layer; i--) matrix[i][layer] = temp[(start + idx++) % size];
}

int main() {
    int m, n, r;
    scanf("%d%d%d", &m, &n, &r);
    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) matrix[i] = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) scanf("%d", &matrix[i][j]);
    int layers = (m < n ? m : n) / 2;
    for (int i = 0; i < layers; i++) rotateLayer(matrix, m, n, i, r);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }
    return 0;
}
