#include <stdio.h>

int main(void) {
    int r, c;
    long long m[100][100];      /* assumes r, c <= 100 */

    if (scanf("%d %d", &r, &c) != 2 || r < 0 || c < 0 || r > 100 || c > 100) {
        printf("Invalid input\n");
        return 1;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (scanf("%lld", &m[i][j]) != 1) {
                printf("Invalid input\n");
                return 1;
            }
        }
    }

    int peaks = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int isPeak = 1;

            if (i > 0     && m[i - 1][j] >= m[i][j]) isPeak = 0;   /* up */
            if (i < r - 1 && m[i + 1][j] >= m[i][j]) isPeak = 0;   /* down */
            if (j > 0     && m[i][j - 1] >= m[i][j]) isPeak = 0;   /* left */
            if (j < c - 1 && m[i][j + 1] >= m[i][j]) isPeak = 0;   /* right */

            if (isPeak) peaks++;
        }
    }

    printf("%d\n", peaks);
    return 0;
}