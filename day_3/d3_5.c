#include<stdio.h>
#include<string.h>

int main() {
    int i = 0, j = 0, max = 0, c = 0;
    char str[200], t[20], m[20];
    printf("Enter a string: ");
    gets(str);
    int l = strlen(str);
    for(i = 0; i < l; i++) {
        if((str[i] != ' ') && (str[i] != '\n')) {
            c++;
            t[j++] = str[i];
        }
        else {
            if(c > max) {
                max = c;
                for(j = 0; j < max; j++) m[j] = t[j];
                m[j] = '\0';
            }
            j = 0;
            c = 0;
        }
    }
    if(c > max) {
        max = c;
        for(j = 0; j < max; j++) m[j] = t[j];
        m[j] = '\0';
    }
    printf("The max length word is '%s' with count = %d", m, max);
    return 0;
}

// Enter a string: This is a string
// The max length word is 'string' with count = 6

// Enter a string: The quick brown fox jumps over the lazy dog.
// The max length word is 'quick' with count = 5