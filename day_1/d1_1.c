// To print neighbor elements base on K position value in Left Array.
// Imagine ChildWorks

#include<stdio.h>

int main() {
    int n, i, mid, k;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: \n");
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);
    mid = (n - 1) / 2;
    printf("Enter the key element K: ");
    scanf("%d", &k);
    if ((k >= 0) && (k <= mid)) {
        if(k == mid) printf("%d", arr[k - 1]);
        else if(k == 0) printf("0  %d", arr[k + 1]);
        else printf("%d  %d", arr[k - 1], arr[k + 1]);
    }
    else printf("Invalid choice of key K");
    return 0;
}

// Output:

// Enter the number of elements in the array: 5
// Enter the elements of the array:
// 1 2 3 4 5
// Enter the key element K: 1
// 1  3