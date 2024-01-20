// To print duplicate letter from string
// Imagine ChildWorks

#include<stdio.h>
int main() {
    char str[100];
    int i, l = 0, flag;
    printf("Enter a string: ");
    gets(str);
    printf("The duplicate characters are: ");
    while(str[l] != '\0') { 
        flag = 0;
        for(i = 0; i < l; i++) {
            if(str[i] == str[l]) flag = 1;
        }
        if(flag == 1) printf("%c", str[l]);
        l++;
    }
    return 0;
}

// Output:
// Enter a string: This is a testing string
// The duplicate characters are: is  sti sting