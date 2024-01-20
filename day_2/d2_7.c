// To find palindrome no's in right array
// Imagine ChildWorks

#include<stdio.h>
int main() {
    int arr[20], i, j, t, c, n, mid;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The palindrome numbers in the right array are: ");
    mid = (n - 1) / 2;
    for(i = mid + 1; i < n; i++) {
        c = arr[i];
        t = 0;
        while(c) {
            t = t * 10 + (c % 10);
            c /= 10;
        }
        if(t == arr[i]) printf(" %d ", arr[i]);
    }
    return 0;
}

// Output:
// Enter the number of elements: 6
// 121 232 343 454 565 676
// The palindrome numbers in the right array are:  454  565  676