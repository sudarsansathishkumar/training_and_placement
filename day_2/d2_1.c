// To print lower case only from string
// Imagine ChildWorks

#include<stdio.h>
#include<ctype.h>
int main() {
    char str[100];
    int i;
    printf("Enter a string: ");
    gets(str);
    printf("The lower case only characters from the string:\n");
    for(i = 0; str[i] != '\0'; i++) {
        if(islower(str[i])) {
            printf("%c", str[i]);
        }
    }
    return 0;
}

// I/P : This Is a TesTinG StrIng
// O/P : hissaesintrng