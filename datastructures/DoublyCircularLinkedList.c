#include <stdio.h>
#include <stdlib.h>

void begininsert();
void traverse();
void lastinsert();
void randominsert();
void randomdelete();
void begindelete();
void enddelete();
void search();
void mid();

struct node {
    struct node *prev;
    struct node *next;
    int data;
}*head;

int main() {
    int c;
    do {
        printf("\n[1] Insert at Beginning\n[2] Insert at End\n[3] Traverse\n[4] Delete at End\n[5] Delete at Beginning\n[6] Search an element\n[7] Random Insert\n[8] Random Delete\n[9] Mid element\n[10] Exit\nEnter your choice: ");
        scanf("%d", &c);
        switch (c) {
        case 1:
            begininsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            traverse();
            break;
        case 4:
            enddelete();
            break;
        case 5:
            begindelete();
            break;
        case 6:
            search();
            break;
        case 7:
            randominsert();
            break;
        case 8:
            randomdelete();
            break;
        case 9:
            mid();
            break;
        case 10:
            printf("Exiting.\n");
            break;
        default:
            printf("Enter a valid choice.\n");
            break;
        }
    } while (c != 10);
    return 0;
}

void begininsert() {
    struct node *ptr, *temp;
    int val;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nUnderFLOW");
    }
    else
    {
        printf("\nEnter  value : ");
        scanf("%d", &val);
        ptr->data = val;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            head->prev = ptr;
            ptr->next = head;
            head = ptr;
        }
        printf("\n Node inserted\n");
    }
}

void traverse() {
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("\n Nothing to print");
    }
    else
    {
        printf("\n Printing values ... \n");
        while (ptr->next != head)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
}

void lastinsert() {
    struct node *ptr, *temp;
    int val;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n UnderFLOW");
    }
    else
    {
        printf("\n Enter value : ");
        scanf("%d", &val);
        ptr->data = val;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            head->prev = ptr;
            ptr->next = head;
        }
    }
    printf("\n Node inserted \n");
}

void randomdelete() {
    struct node *ptr = head;
    int p, i = 0;
    if(ptr == NULL) printf("The list is empty. Underflow error.\n");
    else {
        printf("Enter the position to insert: ");
        scanf("%d", &p);
        if(p == 0) begindelete();
        else {
            while(i < p) {
                ptr = ptr->next;
                if(ptr == head) {
                    printf("Cannot able to locate the provided position.\n");
                    return;
                }
                i++;
            }
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
            printf("Node deleted.\n");
        }
    }
}

void enddelete() {
    struct node *last;
    if(head == NULL) printf("The list is empty.\n");
    else {
        last = head->prev;
        if(last == head) {
            head = NULL;
            free(last);
            printf("Node deleted.\n");
        }
        else {
            last->prev->next = head;
            head->prev = last->prev;
            free(last);
            printf("Node deleted.\n");
        }
    }
}

void begindelete() {
    struct node *front;
    if(head == NULL) printf("The list is empty.\n");
    else {
        front = head;
        if(front == front->next) {
            head = NULL;
            free(front);
            printf("Node deleted.\n");
        }
        else {
            front->prev->next = front->next;
            front->next->prev = front->prev;
            head = front->next;
            free(front);
            printf("Node deleted.\n");
        }
    }
}

void search() {
    struct node *ptr = head;
    int k, found = 0;
    if(ptr == NULL) printf("The list is empty.\n");
    else {
        printf("Enter the value of the node to search: ");
        scanf("%d", &k);
        do{
            if(ptr->data == k) {
                printf("Element found.\n");
                found = 1;
                break;
            }
            ptr = ptr->next;
        }while(ptr != head);
        if(!found) printf("Element not found in the list.\n");
    }
}

void randominsert() {
    struct node *ptr = head, *new = (struct node *)malloc(sizeof(struct node));
    int p, i = 0;
    if(ptr == NULL) printf("The list is empty. Cannot able to locate any positions.\n");
    else {
        printf("Enter the position to insert: ");
        scanf("%d", &p);
        if(p == 0) begininsert();
        else {
            while(i < p) {
                ptr = ptr->next;
                if(ptr == head) {
                    printf("Cannot insert at the provided position.\n");
                    return;
                }
                i++;
            }
            printf("Enter the value of the node: ");
            scanf("%d", &new->data);
            ptr->prev->next = new;
            new->prev = ptr->prev;
            ptr->prev = new;
            new->next = ptr;
        }
    }
}

void mid() {
    int mid, n = 0;
    struct node *ptr = head;
    if(ptr == NULL) printf("The list is empty.\n");
    else {
        do{
            ptr = ptr->next;
            n++;
        }while(ptr != head);
        ptr = head;
        mid = n / 2;
        n = 0;
        while(n < mid - 1){
            ptr = ptr->next;
            n++;
        }
        printf("The mid element is: %d\n", ptr->data);
    }
}