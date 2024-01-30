#include<stdio.h>
#include<stdlib.h>

void addlast();
void swap(int);
void display();

struct node {
    struct node *prev;
    int data;
    struct node *next;
}*head;

int main() {
    int n, i, k;
    printf("Enter the number of nodes in the list: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        addlast();
    }
    do{
        printf("Enter the k value: ");
        scanf("%d", &k);
    }while(k > n);
    printf("The list before swapping:\n");
    display();
    swap(k);
    printf("The list after swapping:\n");
    display();
    return 0;
}

void addlast() {
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d", &ptr->data);
    if(head == NULL) {
        ptr->next = NULL;
        ptr->prev = NULL;
        head = ptr;
    }
    else {
        temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = ptr;
        ptr->prev = temp;
        ptr->next = NULL;
    }
}

void display() {
    struct node *ptr = head;
    if(ptr != NULL) {
        while(ptr != NULL) {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

void swap(int k) {
    struct node *p1, *p2;
    int i = 0;
    p1 = head;
    p2 = head;
    while(i < k - 1) {
        p1 = p1->next;
        i++;
    }
    while(p2->next != NULL) p2 = p2->next;
    i = 0;
    while(i < k - 1) {
        p2 = p2->prev;
        i++;
    }
    i = p1->data;
    p1->data = p2->data;
    p2->data = i;
}
