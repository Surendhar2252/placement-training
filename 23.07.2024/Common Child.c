#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s1[5001], s2[5001];
    scanf("%s%s", s1, s2);
    int n = strlen(s1);
    int dp[n+1][n+1];
    for (int i = 0; i <= n; i++) dp[i][0] = dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = s1[i-1] == s2[j-1] ? dp[i-1][j-1] + 1 : dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
    printf("%d\n", dp[n][n]);
    return 0;
}
