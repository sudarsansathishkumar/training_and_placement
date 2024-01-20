// To print repeated digit elements from array values
// Imagine ChildWorks

#include<stdio.h>
int main() {
    int arr[10] = {789, 53, 222, 666, 54, 98, 55, 1, 3, 166}, i, t, d, flag;
    int n = sizeof(arr) / sizeof(arr[0]);
    for(i = 0; i < n; i++) {
        t = arr[i];
        d = t % 10;
        t /= 10;
        if(t > 0) {
            flag = 0;
            while(t) {
                if (t % 10 != d) {
                    flag = 1;
                    break;
                }
                t /= 10;
            }
            if (flag == 0) printf("%d\t", arr[i]);
        }
    }
    return 0;
}

// Output:
// 222     666     55