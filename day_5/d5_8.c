// To find a permutation of given value from user

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count = 0;

void findPermutations(char *, int, int);
void swap(char *, char *);

struct node {
    char str[20];
    struct node *next;
}*head;

int main() {
    char inp[20];
    printf("Enter a string: ");
    gets(inp);
    printf("The permutations of %s are:\n", inp);
    findPermutations(inp, 0, strlen(inp) - 1);
    printf("The number of permuations of %s = %d", inp, count);
    return 0;
}

void findPermutations(char *inp, int s, int e) {
    int i;
    if(s == e) {
        printf("%s\n", inp);
        count++;
    }
    else {
        for(i = s; i <= e; i++) {
            swap(&inp[s], &inp[i]);
            findPermutations(inp, s + 1, e);
            swap(&inp[s], &inp[i]);
        }
    }
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Enter a string: asdf
// The permutations of asdf are:
// asdf
// asfd
// adsf
// adfs
// afds
// afsd
// sadf
// safd
// sdaf
// sdfa
// sfda
// sfad
// dsaf
// dsfa
// dasf
// dafs
// dfas
// dfsa
// fsda
// fsad
// fdsa
// fdas
// fads
// fasd
// The number of permuations of asdf = 24