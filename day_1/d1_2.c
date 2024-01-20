// To store all even No's in left Slide and Odd No's in right Slide Array(One Array Only)
// Imagine ChildWorks

#include<stdio.h>
int main()
{
int arr[] = {0, 1, 5, 3, 2, 3, 4, 5, 6, 7, 8, 9};
int n = 12; // count of arr
int i=0, j=n, k, temp;
for(k = 0; k< n;k++){
    if(arr[k]%2 == 0){
        temp = arr[i];
        arr[i++] = arr[k];
        arr[k] = temp;
    }
    else {
        temp = arr[j];
        arr[j--]=  arr[k];
        arr[k--] = temp;
    }
    if(i > j) break;
}
for(k = 0; k < n; k++) printf("%d\t", arr[k]);
return 0;
}

// Output :

// I/P: {1, 2, 3, 4, 5}
// O/P: {4, 2, 3, 5, 1}

// I/P: {0, 1, 5, 3, 2, 3, 4, 5, 6, 7, 8, 9}
// O/P: {0, 8, 6, 4, 2, 3, 5, 3, 7, 5, 9, 1}