#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n < 2) {
        printf("Need at least 2 values\n");
        return 1;
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

    unsigned long long best = 0ULL - 1ULL;   /* largest possible unsigned value */

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            unsigned long long diff;
            if (a[i] > a[j])
                diff = (unsigned long long)a[i] - (unsigned long long)a[j];
            else
                diff = (unsigned long long)a[j] - (unsigned long long)a[i];

            if (diff < best) best = diff;
        }
    }

    printf("%llu\n", best);
    free(a);
    return 0;
}