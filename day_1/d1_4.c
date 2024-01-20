// To print how many Armstring no's from array values
// Imagine ChildWorks

#include<stdio.h>
#include<math.h>
int main() {
    int n = 10;
    int a[10] = {1, 2, 153, 245, 370, 407, 568, 987, 1234, 1456}, i, j, c, l, sum, count = 0;
    for(i = 0; i < n; i++) {
        c = a[i];
        l = 0;
        sum = 0;
        while(c) {
            l += 1;
            c /= 10;
        }
        c = a[i];
        for(j = 0; j < l; j++) {
            sum += pow((c % 10), l);
            c /= 10;
        }
        if(sum == a[i]) count++;
    }
    printf("The number of Armstrong numbers in the array = %d", count);
    return 0;
}

// Output:

// The number of Armstrong numbers in the array = 4