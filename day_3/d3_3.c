// Matrix Multiplication

#include<stdio.h>
int main() {
    int a[4][4], b[4][4], c[4][4], i, j, k, sum, n = 3;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("Enter a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("Enter b[%d][%d] = ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            sum = 0;
            for(k = 0; k < n; k++) {
                sum += a[i][k] * a[k][j];
            }
            c[i][j] = sum;
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}