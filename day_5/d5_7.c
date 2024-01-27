// To read stack values and transfer to make 2D array

#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;
}*head;

int main() {
    int t, i, j, n = 0, m = 0, arr[20][20];
    struct node *ptr, *prev;
    printf("Enter number of elements: ");
    scanf("%d", &t);
    for(i = 0; i < t; i++) {
        ptr = (struct node *)malloc(sizeof(struct node));
        if(ptr == NULL) printf("Cannot able to allocate memory.\n");
        else {
            printf("Enter the value: ");
            scanf("%d", &ptr->val);
            if(head == NULL) head = ptr;
            else prev->next = ptr;
            ptr->next = NULL;
            prev = ptr;
        }
    }
    while((m * n) != t) {
        printf("Enter the number of rows and columns: ");
        scanf("%d %d", &m, &n);
        if((m * n) != t) printf("Cannot able to form a 2D array of %dx%d format for %d number of elements.\n", m, n, t);
    }
    ptr = head;
    printf("The array is:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            arr[i][j] = ptr->val;
            ptr = ptr->next;
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// Enter number of elements: 8
// Enter the value: 1
// Enter the value: 2
// Enter the value: 3
// Enter the value: 4
// Enter the value: 5
// Enter the value: 6
// Enter the value: 7
// Enter the value: 8
// Enter the number of rows and columns: 2
// 4
// The array is:
// 1       2       3       4
// 5       6       7       8


// Enter number of elements: 6
// Enter the value: 1
// Enter the value: 2
// Enter the value: 3
// Enter the value: 4
// Enter the value: 5
// Enter the value: 6
// Enter the number of rows and columns: 2
// 3
// The array is:
// 1       2       3
// 4       5       6