#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input\n");
        return 1;
    }
    if (n == 0) {
        printf("0\n");
        return 0;
    }

    long long *a = malloc(n * sizeof(long long));
    if (a == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%lld", &a[i]) != 1) {
            printf("Invalid input\n");
            free(a);
            return 1;
        }
    }

    int current = 1, best = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            current++;
            if (current > best) best = current;
        } else {
            current = 1;
        }
    }

    printf("%d\n", best);
    free(a);
    return 0;
}