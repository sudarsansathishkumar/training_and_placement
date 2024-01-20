// To make an array in unique format
// Imagine ChildWorks

#include<stdio.h>
int main() {
    int arr[20], i, j, n, t, c = 0, flag;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements: \n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &t);
        flag = 0;
        for(j = 0; j <= c; j++) {
            if(arr[j] == t) flag = 1;
        }
        if(flag == 0) arr[c++] = t;
    }
    printf("The array in unique format:\n");
    for(i = 0; i < c; i++) {
        printf(" %d ", arr[i]);
    }
    return 0;
}

// Output:
// Enter the number of elements in the array: 10
// Enter 10 elements:
// 1 2 3 4 5 1 2 3 4 6
// The array in unique format:
//  1  2  3  4  5  6