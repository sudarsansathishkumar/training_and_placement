// To make string in to palindrome
// Imagine ChildWorks

#include<stdio.h>
int main() {
    char str[100];
    int l = 0, i;
    printf("Enter a string: ");
    gets(str);
    while(str[l] != '\0') l++;
    for(i = l - 1; i >= 0 ; i--) {
        str[l++] = str[i];
        printf("%d", i);
    }
    str[l] = '\0';
    printf("The palindrome string is: %s", str);
    return 0;
 }

// I/P : palindrome
// O/P : palindromeemordnilap