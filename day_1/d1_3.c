// To print unique values from array
// Imagine ChildWorks

#include<stdio.h>
int main() {
    int n = 10, flag;
    int a[10] = {1, 2, 6, 2, 5, 1, 4, 5, 3, 8}, b[10], i, j, c = 0;
    for(i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < c; j++) {
            if(a[i] == b[j]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) b[c++] = a[i];
    }
    printf("The Unique elements of the array: \n");
    for(i = 0; i < c; i++) printf("%d\t", b[i]);
    return 0;
}

// Output:

// The Unique elements of the array: 
// 1       2       6       5       4       3       8