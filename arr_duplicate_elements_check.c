// To find whether an array is duplicate array or not

#include<stdio.h>

int verify(int[], int);
int main() {
    int n, arr[10], i;
    printf("Enter the no. of elements in the array: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf((verify(arr, n) == 1) ? "This is a duplicate array" : "This is not a duplicate array");
    return 0;
}

int verify(int arr[], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) return 1;
        }
    }
    return -1;
}

// Enter the no. of elements in the array: 5
// Enter arr[0] = 0
// Enter arr[1] = 1
// Enter arr[2] = 2
// Enter arr[3] = 3
// Enter arr[4] = 4
// This is not a duplicate array

// Enter the no. of elements in the array: 5
// Enter arr[0] = 1
// Enter arr[1] = 2
// Enter arr[2] = 3
// Enter arr[3] = 3
// Enter arr[4] = 4
// This is a duplicate array