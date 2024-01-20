// To check a string is pangram
// Imagine ChildWorks

#include<stdio.h>
#include<ctype.h>
int main() {
    char str[100], t[26];
    int i = 0, j = 0, k, flag;
    printf("Enter a string: ");
    gets(str);
    while(str[i] != '\0') {
        if(isalpha(str[i])) {
            flag = 0;
            for(k = 0; k < j; k++) {
                if(tolower(str[i]) == t[k]) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) t[j++] = tolower(str[i]);
        }
        i++;
    }
    printf((j == 26) ? "The given string is a pangram string" : "The given string is not a pangram string");
    return 0;
}

// Output:

// Enter a string: This is a string   
// The given string is not a pangram string

// Enter a string: The quick brown fox jumps over the lazy dog
// The given string is a pangram string