#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void begininsert();
void traverse();
void lastinsert();
void reversetraverse();
void countlc();
void randominsert();
void begindelete();
void enddelete();
void randomdelete();
void search();

struct node {
    int data; // char data;
    struct node *prev;
    struct node *next;
}*head;

int main() {
    int c;
    do {
        printf("\n[1] Insert at Beginning\n[2] Insert at End\n[3] Traverse\n[4] Reverse Traverse\n[5] Count number of lower case letters\n[6] Delete at Beginning\n[7] Delete at End\n[8] Random Insert\n[9] Random Delete\n[10] Search\n[11] Exit\nEnter your choice: ");
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
                reversetraverse();
                break;
            case 5:
                countlc();
                break;
            case 6:
                begindelete();
                break;
            case 7:
                enddelete();
                break;
            case 8:
                randominsert();
                break;
            case 9:
                randomdelete();
                break;
            case 10:
                search();
                break;
            case 11:
                printf("Exiting...\n");
                break;
            default:
                printf("Enter a valid option.\n");
                break;
        }
    } while (c != 11);
    return 0;
}

void begininsert() {
    struct node *ptr;
    int val;

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n UnderFLOW");
    }
    else
    {
        printf("\nEnter the value which you want to insert? : ");
        scanf("%d", &val);
        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            ptr->data = val;
            head = ptr;
        }
        else
        {
            ptr->data = val;
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        printf("\nNode inserted\n");
    }
}

void traverse() {
    struct node *ptr;

    ptr = head;
    if (head == NULL)
        printf("\nNothing to Print");
    else
    {
        printf("\nPrinting values...\n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

void lastinsert() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n UnderFLOW");
    }
    else
    {
        printf("\n Enter value : ");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
    }
    printf("\n Node inserted at Last \n");
}

void reversetraverse() {
    struct node *ptr;
    ptr = head;
    if(ptr == NULL) printf("The list is empty.\n");
    else {
        printf("The node values in reverse order:\n");
        while(ptr->next != NULL) ptr = ptr->next;
        while(ptr != NULL) {
            printf("%d\n", ptr->data);
            ptr = ptr->prev;
        }
    }
}

void countlc() {
    struct node *ptr = head;
    int count = 0;
    while(ptr != NULL) {
        if(islower(ptr->data)) count++;
        ptr = ptr->next;
    }
    printf("The number of lowercase letters in the list = %d\n", count);
}

void begindelete() {
    struct node *ptr = head;
    if(ptr == NULL) printf("Underflow error...\n");
    else {
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
            free(ptr);
            printf("Node deleted.\n");
        }
        else {
            head = NULL;
            free(ptr);
            printf("Node deleted.\n");
        }
    }
}

void enddelete() {
    struct node *ptr = head;
    if(ptr == NULL) printf("Underflow error...\n");
    else {
        if(ptr->next == NULL) {
            head = NULL;
            free(ptr);
            printf("Node deleted.\n");
        }
        else {
            while(ptr->next != NULL) ptr = ptr->next;
            ptr->prev->next = NULL;
            free(ptr);
        }
    }
}

void randominsert() {
    struct node *ptr = head, *new = (struct node *)malloc(sizeof(struct node));
    int p, i = 0;
    if(ptr == NULL) printf("The list is empty. Cannot able to locate a position.\n");
    else {
        printf("Enter the position to insert: ");
        scanf("%d", &p);
        if(p == 0) begininsert();
        else {
            printf("Enter the value of the node: ");
            scanf("%d", &new->data);
            while(i < p) {
                ptr = ptr->next;
                if(ptr == NULL) {
                    printf("Cannot insert at the provided position.\n");
                    return;
                }
                i++;
            }
            ptr->prev->next = new;
            new->prev = ptr->prev;
            ptr->prev = new;
            new->next = ptr;
        }
    }
}

void search() {
    struct node *ptr = head;
    int k, found = 0;
    if(ptr == NULL) printf("The list is empty.\n");
    else {
        printf("Enter the key value to search in the list: ");
        scanf("%d", &k);
        while(ptr != NULL) {
            if(ptr->data == k) {
                found = 1;
                printf("The element found in the list.\n");
                break;
            }
            ptr = ptr->next;
        }
        if(!found) printf("The element not found in the list.\n");
    }
}

void randomdelete() {
    struct node *ptr = head;
    int p, i = 0;
    if(ptr == NULL) printf("Underflow error...\n");
    else {
        printf("Enter the position of the node to delete: ");
        scanf("%d", &p);
        if(p == 0) begindelete();
        else {
            while(i < p) {
                if(ptr->next != NULL) {
                    ptr = ptr->next;
                }
                else {
                    printf("Position does not exists.\n");
                    return;
                }
                i++;
            }
            if(ptr->next == NULL) ptr->prev->next = NULL;
            else {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
            }
            free(ptr);
            printf("Node deleted.\n");
        }

    }

}