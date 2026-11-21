#include <stdio.h>

int main(void) {
    long long N;

    if (scanf("%lld", &N) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    if (N > 1000000000LL) {
        printf("N too large\n");
        return 1;
    }

    int found = 0;

    for (long long a = 1; a <= N; a++) {
        for (long long b = a + 1; b <= N; b++) {
            long long sum = a * a + b * b;
            for (long long c = b + 1; c <= N; c++) {
                if (c * c > sum) break;          /* c only gets bigger, so stop early */
                if (c * c == sum) {
                    printf("%lld %lld %lld\n", a, b, c);
                    found = 1;
                }
            }
        }
    }

    if (!found) printf("None\n");
    return 0;
}