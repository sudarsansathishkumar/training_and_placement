// To count number of lines in given string
// Imagine ChildWorks

#include<stdio.h>
int main() {
    char str[100];
    int i = 0, c = 1;
    printf("Enter a string: \n");
    scanf("%[^!]", str);
    while(str[i] != '\0') {
        if(str[i] == '\n') c++;
        i++;
    }
    printf("The number of lines entered = %d", c);
    return 0;
}

// Output:
// Enter a string: 
// This  
// is
// a
// string!
// The number of lines entered = 4