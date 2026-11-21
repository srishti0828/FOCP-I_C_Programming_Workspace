#include <stdio.h>
#include <stdlib.h>

long long countPairs(const long long a[], int n, long long target) {
    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {      /* inner loop starts at i+1, as the hint says */
            if (a[i] + a[j] == target) count++;
        }
    }
    return count;
}

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    long long target;

    if (scanf("%d %lld", &n, &target) != 2 || n < 0) {
        printf("Invalid input\n");
        return 1;
    }

    long long *a = malloc((n > 0 ? n : 1) * sizeof(long long));
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

    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == target) count++;
        }
    }

    printf("%lld\n", count);
    free(a);
    return 0;
}