#include <stdio.h>
#include <stdlib.h>

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n;
        scanf("%d", &n);
        int *row_sum = (int *)calloc(n, sizeof(int));
        int *col_sum = (int *)calloc(n, sizeof(int));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int x;
                scanf("%d", &x);
                row_sum[i] += x;
                col_sum[j] += x;
            }
        qsort(row_sum, n, sizeof(int), compare);
        qsort(col_sum, n, sizeof(int), compare);
        int possible = 1;
        for (int i = 0; i < n; i++)
            if (row_sum[i] != col_sum[i]) {
                possible = 0;
                break;
            }
        printf("%s\n", possible ? "Possible" : "Impossible");
        free(row_sum);
        free(col_sum);
    }
    return 0;
}
