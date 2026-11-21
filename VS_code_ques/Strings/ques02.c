#include <stdio.h>

int main(void) {
    int c;
    int prev = -1;           
    long long count = 0;

    while ((c = getchar()) != EOF && c != '\n') {
        if (c == '\r') continue;          
        if (c == prev) {
            count++;
        } else {
            if (prev != -1)
                printf("%c%lld", prev, count);   
            prev = c;
            count = 1;
        }
    }

    if (prev != -1)
        printf("%c%lld", prev, count);           

    printf("\n");
    return 0;
}