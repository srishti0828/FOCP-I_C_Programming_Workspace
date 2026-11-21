#include <stdio.h>

int main(void) {
    int r, c;
    long long m[100][100];      

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

    int found = 0;

    for (int i = 0; i < r && !found; i++) {
        for (int j = 0; j < c; j++) {
            int isRowMin = 1, isColMax = 1;

            for (int k = 0; k < c; k++) {              
                if (m[i][k] < m[i][j]) { isRowMin = 0; break; }
            }
            for (int k = 0; k < r; k++) {              
                if (m[k][j] > m[i][j]) { isColMax = 0; break; }
            }

            if (isRowMin && isColMax) {
                printf("%d %d %lld\n", i, j, m[i][j]);
                found = 1;
                break;                                 
            }
        }
    }

    if (!found) printf("None\n");
    return 0;
}