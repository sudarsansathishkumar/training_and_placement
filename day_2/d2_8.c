// To convert all vowels into uppercase
// Imagine ChildWorks

#include<stdio.h>
#include<ctype.h>
int main() {
    char str[100];
    int i = 0;
    printf("Enter a string: ");
    gets(str);
    printf("After converting all the vowel to uppercase: ");
    while(str[i] != '\0') {
        if((str[i] == 'a')||(str[i] == 'e')||(str[i] == 'i')||(str[i] == 'o')||(str[i] == 'u')) {
            str[i] = toupper(str[i]);
        }
        printf("%c", str[i]);
        i++;
    }
    return 0;
}

// Output:
// Enter a string: This is a string
// After converting all the vowel to uppercase: ThIs Is A strIng