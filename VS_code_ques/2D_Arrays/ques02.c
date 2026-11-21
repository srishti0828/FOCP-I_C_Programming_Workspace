#include <stdio.h>

int main(void) {
    int n;
    long long m[100][100];      /* assumes n <= 100 */

    if (scanf("%d", &n) != 1 || n < 0 || n > 100) {
        printf("Invalid input\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%lld", &m[i][j]) != 1) {
                printf("Invalid input\n");
                return 1;
            }
        }
    }

    int symmetric = 1;

    for (int i = 0; i < n && symmetric; i++) {
        for (int j = i + 1; j < n; j++) {      /* only above the main diagonal */
            if (m[i][j] != m[j][i]) {
                symmetric = 0;
                break;
            }
        }
    }

    printf("%s\n", symmetric ? "YES" : "NO");
    return 0;
}