// To print only digits from string using Array of Stack

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

void printdigits(char[], int);

int main() {
    char stack[100];
    int top = -1;
    printf("Enter a string: ");
    gets(stack);
    top = strlen(stack) - 1;
    printdigits(stack, top);
    return 0;
}

void printdigits(char stack[], int top) {
    if(top != -1) {
        printf("The digits present in the stack are: \n");
        while(top != -1) {
            if(isdigit(stack[top])) {
                printf("%c ", stack[top]);
            }
            top--;
        }
    }
}

// Enter a string: This 1 is a 2 string with 3 digits
// The digits present in the stack are:
// 3 2 1