// To count number of repeated letter from node lists

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char letters[26];

struct node {
    char str[20];
    struct node *next;
}*head;

int main() {
    int i, n, j, k, flag, count = 0;
    struct node *ptr, *prev;
    printf("Enter the number of node: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        ptr = (struct node *)malloc(sizeof(struct node));
        printf("Enter the input: ");
        scanf("%s", ptr->str);
        if(head == NULL) head = ptr;
        else prev->next = ptr;
        ptr->next = NULL;
        prev = ptr;
    }
    ptr = head;
    i = 0;
    while(ptr != NULL) {
        for(k = 0; k < strlen(ptr->str); k++) {
            flag = 1;
            for(j = 0; j < i; j++) {
                if(ptr->str[k] == letters[j]) flag = 0;
            }
            if(flag) letters[i++] = ptr->str[k];
            else count++;
        }
        ptr = ptr->next;
    }
    printf("The number of repeated letter from node list: %d", count);
    return 0;
}

// Enter the number of node: 5
// Enter the input: asdf
// Enter the input: qwer
// Enter the input: alkj
// Enter the input: p
// Enter the input: o
// The number of repeated letter from node list: 1

// Enter the number of node: 5
// Enter the input: asdf
// Enter the input: asdf
// Enter the input: asfd
// Enter the input: asdf
// Enter the input: asdf
// The number of repeated letter from node list: 16