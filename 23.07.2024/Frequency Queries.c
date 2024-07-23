#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

int main() {
    int q;
    scanf("%d", &q);
    int *freq = (int *)calloc(MAX + 1, sizeof(int));
    int *count = (int *)calloc(MAX + 1, sizeof(int));
    while (q--) {
        int type, x;
        scanf("%d%d", &type, &x);
        if (type == 1) {
            if (freq[x]) count[freq[x]]--;
            freq[x]++;
            count[freq[x]]++;
        } else if (type == 2) {
            if (freq[x]) {
                count[freq[x]]--;
                freq[x]--;
                count[freq[x]]++;
            }
        } else if (type == 3) {
            printf("%d\n", count[x] > 0);
        }
    }
    free(freq);
    free(count);
    return 0;
}
