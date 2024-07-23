#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *ratings = (int *)malloc(n * sizeof(int));
    int *candies = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &ratings[i]);
        candies[i] = 1;
    }
    for (int i = 1; i < n; i++)
        if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
    for (int i = n - 2; i >= 0; i--)
        if (ratings[i] > ratings[i + 1]) candies[i] = max(candies[i], candies[i + 1] + 1);
    int total = 0;
    for (int i = 0; i < n; i++) total += candies[i];
    printf("%d\n", total);
    free(ratings);
    free(candies);
    return 0;
}
