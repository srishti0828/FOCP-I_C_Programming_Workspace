#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int r, c;

    if (scanf("%d %d", &r, &c) != 2 || r < 0 || c < 0) {
        printf("Invalid input\n");
        return 1;
    }

    long long *rowSum = calloc(r > 0 ? r : 1, sizeof(long long));
    long long *colSum = calloc(c > 0 ? c : 1, sizeof(long long));
    if (rowSum == NULL || colSum == NULL) {
        printf("Memory allocation failed\n");
        free(rowSum);
        free(colSum);
        return 1;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            long long x;
            if (scanf("%lld", &x) != 1) {
                printf("Invalid input\n");
                free(rowSum);
                free(colSum);
                return 1;
            }
            rowSum[i] += x;
            colSum[j] += x;
        }
    }

    for (int i = 0; i < r; i++) {
        if (i > 0) printf(" ");
        printf("%lld", rowSum[i]);
    }
    printf("\n");

    for (int j = 0; j < c; j++) {
        if (j > 0) printf(" ");
        printf("%lld", colSum[j]);
    }
    printf("\n");

    free(rowSum);
    free(colSum);
    return 0;
}