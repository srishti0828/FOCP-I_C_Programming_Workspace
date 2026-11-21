#include <stdio.h>

int isPerfectSquare(long long n) {
    if (n < 0) return 0;              
    long long lo = 0;
    long long hi = 3037000499LL;      

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        long long sq = mid * mid;

        if (sq == n) return 1;
        if (sq < n) lo = mid + 1;
        else        hi = mid - 1;
    }
    return 0;
}

int main(void) {
    long long n;

    if (scanf("%lld", &n) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    printf("%d\n", isPerfectSquare(n));
    return 0;
}