#include <stdio.h>
#include <limits.h>

long long rectangleArea(long long length, long long width) {
    return length * width;
}

int main(void) {
    long long length, width;

    if (scanf("%lld %lld", &length, &width) != 2) {
        printf("Invalid input\n");
        return 1;
    }

    if (length < 0 || width < 0) {
        printf("Length and width cannot be negative\n");
        return 1;
    }

    if (length != 0 && width > LLONG_MAX / length) {
        printf("Area is too large for long long\n");
        return 1;
    }

    printf("%lld\n", rectangleArea(length, width));
    return 0;
}