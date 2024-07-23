#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isMultiple(int num, int n) {
    return num % n == 0;
}

void findSpecialMultiple(int n) {
    char queue[100000][100], temp[100];
    int front = 0, rear = 0;
    strcpy(queue[rear++], "9");
    while (1) {
        strcpy(temp, queue[front++]);
        int num = atoi(temp);
        if (isMultiple(num, n)) {
            printf("%s\n", temp);
            return;
        }
        strcpy(queue[rear], temp);
        strcat(queue[rear++], "0");
        strcpy(queue[rear], temp);
        strcat(queue[rear++], "9");
    }
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        findSpecialMultiple(n);
    }
    return 0;
}
