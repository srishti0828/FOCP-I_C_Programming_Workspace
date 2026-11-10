#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int m = (n + 1) / 2;                       

    for (int i = 1; i <= n; i++) {             
        int k = (i <= m) ? i : n - i + 1;      
        int gap = 2 * (m - k) + 3;             

        for (int j = 1; j <= k; j++)           
            printf("*");
        for (int s = 1; s <= gap; s++)         
            printf(" ");
        for (int j = 1; j <= k; j++)           
            printf("*");
        printf("\n");
    }

    return 0;
}