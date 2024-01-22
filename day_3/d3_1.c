// To convert the array elements to equal elements by incrementing it

#include<stdio.h>
int main() {
    int n, arr[10], i, j, max, min, flag = 0, count = 0;
    printf("Enter the no. of elements in the array: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter arr[%d] = ", i);
        scanf("%d", &arr[i]);
        if(i == 0) {
            min = arr[i];
            max = arr[i];
        }
        else {
            if(max < arr[i]) max = arr[i];
            if(min > arr[i]) min = arr[i];
        }

    }
    if(min == max) printf("\nCount = 0\n");
    else {
        while(!flag) {
            flag = 1;
            for(i = 0; i < n; i++) {
                if(arr[i] == max - 1) arr[i]++;
                else if(arr[i] < max - 1) {
                    arr[i]++;
                    flag = 0;
                }
            }
            count++;
        }
        printf("\nCount = %d\n", count);
    }
        for(i = 0; i < n; i++) {
            printf(" %d ", arr[i]);
        }
    return 0;
}

// Enter the no. of elements in the array: 3
// Enter arr[0] = 1
// Enter arr[1] = 1
// Enter arr[2] = 1

// Count = 0
//  1  1  1 

// Enter the no. of elements in the array: 5
// Enter arr[0] = 5
// Enter arr[1] = 2
// Enter arr[2] = 4
// Enter arr[3] = 3
// Enter arr[4] = 1

// Count = 4
//  5  5  5  5  5