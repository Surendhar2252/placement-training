#include <stdio.h>
#include <stdlib.h>

int minMoves(int n, int a, int b) {
    int **board = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) board[i] = (int *)calloc(n, sizeof(int));
    int moves[8][2] = {{a, b}, {a, -b}, {-a, b}, {-a, -b}, {b, a}, {b, -a}, {-b, a}, {-b, -a}};
    int front = 0, rear = 0, queue[10000][2];
    queue[rear][0] = 0;
    queue[rear++][1] = 0;
    board[0][0] = 1;
    while (front < rear) {
        int x = queue[front][0];
        int y = queue[front++][1];
        for (int i = 0; i < 8; i++) {
            int newX = x + moves[i][0];
            int newY = y + moves[i][1];
            if (newX >= 0 && newY >= 0 && newX < n && newY < n && !board[newX][newY]) {
                queue[rear][0] = newX;
                queue[rear++][1] = newY;
                board[newX][newY] = board[x][y] + 1;
            }
        }
    }
    int result = board[n-1][n-1] ? board[n-1][n-1] - 1 : -1;
    for (int i = 0; i < n; i++) free(board[i]);
    free(board);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            printf("%d ", minMoves(n, i, j));
        }
        printf("\n");
    }
    return 0;
}
