#include <stdio.h>

int main(void) {
    long long n, m;

    if (scanf("%lld %lld", &n, &m) != 2) {
        printf("Invalid input\n");
        return 1;
    }

    unsigned long long absN = (n < 0) ? 0ULL - (unsigned long long)n : (unsigned long long)n;
    long long count = 0;

    for (long long x = 1; x <= m; x++) {
        unsigned long long p = (unsigned long long)x;
        unsigned long long q = absN;

        while (q != 0) {            /* Euclid's algorithm, inline */
            unsigned long long r = p % q;
            p = q;
            q = r;
        }

        if (p == 1) count++;
    }

    printf("%lld\n", count);
    return 0;
}