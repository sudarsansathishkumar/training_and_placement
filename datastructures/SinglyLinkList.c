#include<stdio.h>
#include<stdlib.h>

/**
 * Menu of Operations:
 * [1] Insert at the beginning
 * [2] Insert at the end
 * [3] Delete at the beginning
 * [4] Delete at the end
 * [5] Traverse the linked list
 * [6] Search a key
 * [7] Random insert
 * [8] Random delete
 * [9] Exit
 */

void insertbegin();
void insertend();
void deletebegin();
void deleteend();
void traverse();
void search();
void randominsert();
void randomdelete();

struct node {
    int data;
    struct node *next;
}*head;

int main() {
    int c;
    do
    {
        printf("\n[1] Insert at Beginning\n[2] Insert at End\n[3] Delete at Beginning\n[4] Delete at End\n[5] Traverse\n[6] Search\n[7] Random Insert\n[8] Random Delete\n[9] Exit\nEnter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insertbegin();
            break;
        case 2:
            insertend();
            break;
        case 3:
            deletebegin();
            break;
        case 4:
            deleteend();
            break;
        case 5:
            traverse();
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
            printf("Exiting...\n");
            break;
        default:
            printf("Enter a valid choice!");
        }
    } while (c != 9);
    return 0;
}

void insertbegin() {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &ptr->data);
    ptr->next = head;
    head = ptr;
    printf("Node inserted.\n");
}

void insertend() {
    struct node *ptr, *last;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    last = head;
    while(last->next != NULL) last = last->next;
    last->next = ptr;
    printf("Node inserted.\n");
}

void traverse() {
    struct node *ptr = head;
    if(ptr == NULL) printf("The list is empty.\n");
    else {
        while(ptr != NULL) {
            printf("%d  ", ptr->data);
            ptr = ptr->next;
        }
    }
}

void deletebegin() {
    struct node *ptr;
    ptr = head;
    if(ptr == NULL) printf("Underflow error...\n");
    else if(ptr->next == NULL) {
        head = NULL;
        free(ptr);
        printf("Node deleted.\n");
    }
    else {
        head = ptr->next;
        free(ptr);
        printf("Node deleted.\n");
    }
}

void deleteend() {
    struct node *ptr, *prev;
    ptr = head;
    if(ptr == NULL) printf("Underflow error...\n");
    else if(ptr->next == NULL) {
        head = NULL;
        free(ptr);
        printf("Node deleted.\n");
    }
    else {
        while(ptr->next != NULL) {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = NULL;
        free(ptr);
        printf("Node deleted.\n");
    }
}

void search() {
    int key, found = 0, n = 0;
    struct node *ptr;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    ptr = head;
    while(ptr != NULL) {
        if((n % 2 == 0) && (ptr->data == key)) {
            found = 1;
            printf("Element found at index %d\n", n);
        }
        if(found) break;
        n++;
        ptr = ptr->next;
    }
}

void randominsert() {
    struct node *ptr, *prev, *new;
    int p, c = 0;
    printf("Enter the position to insert: ");
    scanf("%d", &p);
    if(p < 0) printf("Position value should be greater than 0.");
    else if(p == 0) insertbegin();
    else {
        ptr = head;
        while(c < p) {
            prev = ptr;
            ptr = ptr->next;
            if(ptr == NULL) {
                printf("Cannot insert an element at the provided position.\n");
                return;
            }
            c++;
        }
        new = (struct node *)malloc(sizeof(struct node));
        printf("%d %d", prev->data, ptr->data);
        printf("Enter the data: ");
        scanf("%d", &c);
        new->data = c;
        prev->next = new;
        new->next = ptr;
        printf("Node inserted.\n");
    }
}

void randomdelete() {
    int p, i = 0;
    printf("Enter the position of the node to delete: ");
    scanf("%d", &p);
    struct node *ptr, *prev;
    ptr = head;
    if(p == 0) deletebegin();
    else {
        if(ptr == NULL) printf("Underflow error...\n");
        else {
            while(i < p) {
                if(ptr->next != NULL) {
                    prev = ptr;
                    ptr = ptr->next;
                }
                else {
                    printf("Position does not exists.\n");
                    return;
                }
                i++;
            }
            if(ptr->next == NULL) {
                prev->next = NULL;
                free(ptr);
                printf("Node deleted.\n");
            }
            else {
                prev->next = ptr->next;
                free(ptr);
                printf("Node deleted.\n");
            }
        }
    }
}