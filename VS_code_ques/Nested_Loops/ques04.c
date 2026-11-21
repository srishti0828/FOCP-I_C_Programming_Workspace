#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input\n");
        return 1;
    }

    int *ds = malloc((n > 0 ? n : 1) * sizeof(int));   /* digit sum of each value */
    if (ds == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        long long x;
        if (scanf("%lld", &x) != 1) {
            printf("Invalid input\n");
            free(ds);
            return 1;
        }

        unsigned long long v = (x < 0) ? 0ULL - (unsigned long long)x : (unsigned long long)x;
        int sum = 0;
        while (v > 0) {
            sum += (int)(v % 10);
            v /= 10;
        }
        ds[i] = sum;
    }

    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i] == ds[j]) count++;
        }
    }

    printf("%lld\n", count);
    free(ds);
    return 0;
}