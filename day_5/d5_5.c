// Perform transpose of Matrix apply dynamic array format

#include<stdio.h>
#include<stdlib.h>

int main() {
    int m, n, **matrix, **transpose, i, j;
    printf("Enter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);
    matrix = (int **)malloc(m * sizeof(int *));
    transpose = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    for(i = 0; i < n; i++) {
        transpose[i] = (int *)malloc(m * sizeof(int));
    }
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("Enter matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
            transpose[j][i] = matrix[i][j];
        }
    }
    printf("The matrix is:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("The transpose of the matrix is:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// Enter number of rows: 2
// Enter number of columns: 3
// Enter matrix[0][0]: 1
// Enter matrix[0][1]: 2
// Enter matrix[0][2]: 3
// Enter matrix[1][0]: 4
// Enter matrix[1][1]: 5
// Enter matrix[1][2]: 6
// The matrix is:
// 1       2       3
// 4       5       6
// The transpose of the matrix is:
// 1       4
// 2       5
// 3       6