// Matrix Multiplication

#include<stdio.h>

int n = 4;

void mat_mul(int[][n], int[][n]);

int main() {
    int a[n][n], b[n][n], i, j, sum;
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
    printf("Matrix a = \n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Matrix b = \n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    mat_mul(a, b);
    return 0;
}

void mat_mul(int a[][n], int b[][n]) {
    int i, j, sum, c[4][4], k;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            sum = 0;
            for(k = 0; k < n; k++) {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
    printf("a * b = \n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

// Enter a[0][0] = 1
// Enter a[0][1] = 2
// Enter a[0][2] = 3
// Enter a[0][3] = 4
// Enter a[1][0] = 5
// Enter a[1][1] = 6
// Enter a[1][2] = 7
// Enter a[1][3] = 8
// Enter a[2][0] = 9
// Enter a[2][1] = 10
// Enter a[2][2] = 11
// Enter a[2][3] = 12
// Enter a[3][0] = 13
// Enter a[3][1] = 14
// Enter a[3][2] = 15
// Enter a[3][3] = 16
// Enter b[0][0] = 1
// Enter b[0][1] = 2
// Enter b[0][2] = 3
// Enter b[0][3] = 4
// Enter b[1][0] = 5
// Enter b[1][1] = 6
// Enter b[1][2] = 7
// Enter b[1][3] = 8
// Enter b[2][0] = 9
// Enter b[2][1] = 10
// Enter b[2][2] = 11
// Enter b[2][3] = 12
// Enter b[3][0] = 13
// Enter b[3][1] = 14
// Enter b[3][2] = 15
// Enter b[3][3] = 16
// Matrix a =
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16
// Matrix b =
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16
// a * b =
// 90 100 110 120
// 202 228 254 280
// 314 356 398 440
// 426 484 542 600