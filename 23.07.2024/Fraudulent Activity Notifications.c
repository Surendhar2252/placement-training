#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(int *count, int x) {
    count[x]++;
}

void remove(int *count, int x) {
    count[x]--;
}

int findMedian(int *count, int d) {
    int prefix_sum = 0;
    for (int i = 0; i < 201; i++) {
        prefix_sum += count[i];
        if (2 * prefix_sum == d) {
            return 2 * i + 1;
        } else if (2 * prefix_sum > d) {
            return 2 * i;
        }
    }
    return -1;
}

int main() {
    int n, d;
    scanf("%d%d", &n, &d);
    int *expenditure = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &expenditure[i]);
    int *count = (int *)calloc(201, sizeof(int));
    for (int i = 0; i < d; i++) insert(count, expenditure[i]);
    int notifications = 0;
    for (int i = d; i < n; i++) {
        int median = findMedian(count, d);
        if (expenditure[i] >= median) notifications++;
        remove(count, expenditure[i - d]);
        insert(count, expenditure[i]);
    }
    printf("%d\n", notifications);
    free(expenditure);
    free(count);
    return 0;
}
