// To count only prime no's from array value
// Imagine ChildWorks

#include <stdio.h>
int main()
{
    int n = 10;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, i, j, count = 0, flag, c;
    for(i = 0; i < n; i++)
    {
        if(arr[i] != 1)
        {
            flag = 0;
            for(j = 2; j <= arr[i] / 2; j++)
            {
                if (arr[i] % j == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) count++;
        }
    }
    printf("The number of prime numbers in the array = %d", count);
    return 0;
}

// Output:

// The number of prime numbers in the array = 4