#include<stdio.h>

int count(int[], int);

int main() {
    int arr[20], i, n;
    printf("Enter the no. of elements in the array: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter a[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("The number of prime numbers in the array = %d", count(arr, n));
    return 0;
}

int count(int arr[], int n) {
    int i, j, c = 0, t;
    for(i = 0; i < n; i++) {
        t = 1;
        for(j = 2; j < i; j++) {
            if(arr[i] % j == 0) {
                t = 0;
                break;
            }
        }
        if(t && (arr[i] != 1)) c++;
    }
    return c;
}

// Enter the no. of elements in the array: 10
// Enter a[0] = 1
// Enter a[1] = 2
// Enter a[2] = 3
// Enter a[3] = 4
// Enter a[4] = 5
// Enter a[5] = 6
// Enter a[6] = 7
// Enter a[7] = 8
// Enter a[8] = 9
// Enter a[9] = 10
// The number of prime numbers in the array = 4