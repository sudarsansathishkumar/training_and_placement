// To convert all space as "," from given string
// Imagine ChildWorks

#include<stdio.h>
#include<ctype.h>
int main() {
    char str[100];
    int i;
    printf("Enter a string: ");
    gets(str);
    printf("After replacing space with ',' :\n");
    for(i = 0; str[i] != '\0'; i++) {
        if(isspace(str[i])) str[i] = ',';
        printf("%c", str[i]);
    }
    return 0;
}

// I/P : This is a string
// O/P : This,is,a,string