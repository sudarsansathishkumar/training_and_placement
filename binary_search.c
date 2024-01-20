// To implement binary search in a sorted array
// Imagine ChildWorks

#include<stdio.h>
int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, k, i, mid, start = 0, end = 10, flag = 0;
    printf("Enter the search key: ");
    scanf("%d", &k);
    while(start < end) {
        mid = (start + end) / 2;
        if(arr[mid] == k) {
            printf("Element found at index: %d", mid);
            flag = 1;
            break;
        }
        else if (arr[mid] < k) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
    if (flag == 0) {
        printf("%d not found in the array", k);
    }
    return 0;
}

int binarysearch(int arr[], int k, int start, int end){
    
}
