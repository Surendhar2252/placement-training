#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reduceString(char *str) {
    int len = strlen(str);
    if (len < 2) return len;
    for (int i = 0; i < len - 1; i++) {
        if (str[i] == str[i + 1]) {
            memmove(&str[i], &str[i + 2], len - i - 1);
            str[len - 2] = '\0';
            return reduceString(str);
        }
    }
    return len;
}

int main() {
    char str[100];
    scanf("%s", str);
    printf("%d\n", reduceString(str));
    return 0;
}
