// To read a node value and verify palindrome or not

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

bool isPalindrome(int);

struct node {
    int val;
    struct node *next;
}*head;

int main() {
    struct node *ptr, *prev;
    int n, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        ptr = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value: ");
        scanf("%d", &ptr->val);
        if(head == NULL) head = ptr;
        else prev->next = ptr;
        ptr->next = NULL;
        prev = ptr;
    }
    ptr = head;
    while(ptr != NULL) {
        if(isPalindrome(ptr->val))  printf("%d is a Palindrome\n", ptr->val);
        else printf("%d is not a Palindrome\n", ptr->val);
        ptr = ptr->next;
    }
    return 0;
}

bool isPalindrome(int v) {
    int l = log10(v) + 1, i, flag = 0, t = 0, b = v;
    while(b) {
        t = (10 * t) + (b % 10);
        b /= 10;
    }
    return (t == v) ?  true :  false;
}

// Enter the number of nodes: 5
// Enter the value: 102
// Enter the value: 232
// Enter the value: 5252525
// Enter the value: 486
// Enter the value: 5
// 102 is not a Palindrome
// 232 is a Palindrome
// 5252525 is a Palindrome
// 486 is not a Palindrome
// 5 is a Palindrome