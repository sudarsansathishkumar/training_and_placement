// To print duck numbers from stack using linked list

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void checkducknumber(char[]);

struct stack {
    char val[10];
    struct stack *next;
} *head;

int main() {
    struct stack *ptr;
    int i, n;
    char v[10];
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        ptr = (struct stack *)malloc(sizeof(struct stack));
        if(ptr == NULL) printf("Cannot able to allocate memory.\n");
        else {
            printf("Enter value for stack[%d]: ", i);
            scanf("%s", ptr->val);
            if(head == NULL) ptr->next = NULL;
            else ptr->next = head;
            head = ptr;
            printf("Element added to the stack.\n");
        }
    }
    ptr = head;
    printf("The duck numbers in the stack are:\n");
    while(ptr != NULL) {
        strcpy(v, ptr->val);
        checkducknumber(v);
        ptr = ptr->next;
    }
    return 0;
}

void checkducknumber(char val[]) {
    int t = 1;
    if(val[0] != '0') {
        while(val[t] != '\0') {
            if(val[t] == '0') {
                printf("%s ", val);
                break;
            }
            t++;
        }
    }
}

// Enter the number of elements in the stack: 3
// Enter value for stack[0]: 012
// Element added to the stack.
// Enter value for stack[1]: 1023
// Element added to the stack.
// Enter value for stack[2]: 256
// Element added to the stack.
// The duck numbers in the stack are:
// 1023