#include <stdio.h>

unsigned long long absValue(long long x) {
    if (x < 0) return 0ULL - (unsigned long long)x;   
    return (unsigned long long)x;
}

unsigned long long gcd(long long a, long long b) {
    unsigned long long x = absValue(a);
    unsigned long long y = absValue(b);

    while (y != 0) {
        unsigned long long r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main(void) {
    long long a, b;

    if (scanf("%lld %lld", &a, &b) != 2) {
        printf("Invalid input\n");
        return 1;
    }

    if (a == 0 && b == 0) {
        printf("GCD is undefined when both inputs are zero\n");
        return 1;
    }

    printf("%llu\n", gcd(a, b));
    return 0;
}