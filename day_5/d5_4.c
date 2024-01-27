// To read array values and replace that values in Odd node List

#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;
}*head;

int main() {
    struct node *ptr;
    int arr[100], i, n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n; i++) {
        ptr = (struct node *)malloc(sizeof(struct node));
        if(ptr == NULL) printf("Cannot able to allocate memory.\n");
        else {
            if((i + 1) % 2 == 1) {
                printf("Enter the value: ");
                scanf("%d", &ptr->val);
            }
            else ptr->val = arr[i];
            if(head == NULL) ptr->next = NULL;
            else ptr->next = head;
            head = ptr;
        }
    }
    printf("The stack after replacing the odd node values is:\n");
    ptr = head;
    while(ptr != NULL) {
        printf("%d\n", ptr->val);
        ptr = ptr->next;
    }
    return 0;
}

// Enter the number of elements in the array: 5
// Enter arr[0]: 1
// Enter arr[1]: 2
// Enter arr[2]: 3
// Enter arr[3]: 4
// Enter arr[4]: 5
// Enter the value: 6
// Enter the value: 7
// Enter the value: 8
// The stack after replacing the odd node values is:
// 8
// 4
// 7
// 2
// 6