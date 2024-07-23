#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int B[n], low = 0, high = 0;
        for (int i = 0; i < n; i++) scanf("%d", &B[i]);
        for (int i = 1; i < n; i++) {
            int low_to_low = low;
            int low_to_high = low + abs(B[i] - 1);
            int high_to_low = high + abs(B[i - 1] - 1);
            int high_to_high = high + abs(B[i] - B[i - 1]);
            low = max(low_to_low, high_to_low);
            high = max(low_to_high, high_to_high);
        }
        printf("%d\n", max(low, high));
    }
    return 0;
}
