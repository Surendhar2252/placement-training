#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *nums[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", 
                      "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", 
                      "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", 
                      "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", 
                      "twenty nine"};

int main() {
    int h, m;
    scanf("%d%d", &h, &m);
    if (m == 0) printf("%s o' clock\n", nums[h]);
    else if (m == 1) printf("one minute past %s\n", nums[h]);
    else if (m == 15) printf("quarter past %s\n", nums[h]);
    else if (m == 30) printf("half past %s\n", nums[h]);
    else if (m == 45) printf("quarter to %s\n", nums[(h % 12) + 1]);
    else if (m < 30) printf("%s minutes past %s\n", nums[m], nums[h]);
    else printf("%s minutes to %s\n", nums[60 - m], nums[(h % 12) + 1]);
    return 0;
}
