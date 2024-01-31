#include <stdio.h>
#include <stdlib.h>

void begininsert();
void traverse();
void lastinsert();
void begindelete();
void enddelete();
void search();
void findleftmax();
void randomdelete();
void minrightlist();

struct node
{
    int data;
    struct node *next;
};
struct node *head;

int main() {
    int c;
    do
    {
        printf("\n[1] Insert at beginning\n[2] Insert at end\n[3] Traverse\n[4] Find left max\n[5] Random Delete\n[6] Minimum value in the right list\n[7] Maximum value in the left list\n[8] Delete at End\n[9] Search an element\n[10] Exit\nEnter your choice: ");
        scanf("%d", &c);
        switch(c) {
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
                findleftmax();
                break;
            case 5:
                randomdelete();
                break;
            case 6:
                minrightlist();
                break;
            case 7:
                findleftmax();
                break;
            case 8:
                enddelete();
                break;
            case 9:
                search();
                break;
            case 10:
                printf("Exiting...\n");
                break;
            default:
                break;
        }
    } while (c != 10);
    return 0;
}

void begininsert()
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) printf("UnderFLOW\n");
    else
    {
        printf("Enter the node data: ");
        scanf("%d", &ptr->data);
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head) temp = temp->next;
            ptr->next = head;
            temp->next = ptr;
            head = ptr;
        }
        printf("Node inserted.\n");
    }
}

void traverse()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL) printf("The list is empty.\n");
    else
    {
        printf("The list is:\n");
        while (ptr->next != head)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
}

void lastinsert()
{
    struct node *ptr, *temp;
    int val;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) printf("Underflow.\n");
    else
    {
        printf("Enter Data: ");
        scanf("%d", &val);
        ptr->data = val;

        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = ptr;
            ptr->next = head;
        }
    }
}

void enddelete() {
    struct node *ptr = head, *prev;
    if(ptr == NULL) printf("The list is empty. Underflow error.\n");
    else {
        if(ptr->next == ptr) {
            head = NULL;
            free(ptr);
            printf("Node deleted.\n");
        }
        else {
            do {
                prev = ptr;
                ptr = ptr->next;
            }while(ptr->next != head);
            prev->next = head;
            free(ptr);
            printf("Node deleted.\n");
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
        do {
            if(ptr->data == k) {
                found = 1;
                printf("Element found in the list.\n");
                break;
            }
        }while(ptr != head);
        if(!found) printf("Element not found in the list.\n");
    }
}

void findleftmax() {
    int c = 0, mid, i = 0, max;
    struct node *temp;
    temp = head;
    if(temp == NULL) printf("The list is empty.\n");
    else {
        if(temp->next == head) {
            max = temp->data;
            printf("Only one node is present in the list.\n");
        }
        else {
            while(temp->next != head) {
                c++;
                temp = temp->next;
            }
            mid = c / 2;
            temp = head;
            max = temp->data;
            while(i <= mid) {
                if(temp->data > max) max = temp->data;
                temp = temp->next;
                i++;
            }
        }
        printf("The maximum element is: %d", max);
    }
}

void begindelete() {
    struct node *ptr = head;
    if(head == NULL) printf("The list is empty.\n");
    else if(ptr->next == head) {
        head = NULL;
        free(ptr);
        printf("Node deleted.\n");
    }
    else {
        while(ptr->next != head) ptr = ptr->next;
        ptr->next = head->next;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Node deleted.\n");
    }
}

void randomdelete() {
    int p, i = 0;
    struct node *ptr, *prev;
    printf("Enter the position of the element to delete: ");
    scanf("%d", &p);
    if(p < 0) printf("Enter a valid position.\n");
    else {
        if(p == 0) begindelete();
        else {
            ptr = head;
            if(ptr == NULL) printf("Underflow error...\n");
            else {
                while(i < p) {
                    if(ptr->next != head) {
                        prev = ptr;
                        ptr = ptr->next;
                    }
                    else {
                        printf("Position does not exists.\n");
                        return;
                    }
                    i++;
                }
                if(ptr->next == head) {
                    prev->next = head;
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
}

void minrightlist() {
    int c = 0, mid, i = 0, min;
    struct node *ptr = head;
    while(ptr->next != head) {
        c++;
        ptr = ptr->next;
    }
    mid = c / 2;
    ptr = head->next;
    while(ptr != head) {
        if(i >= mid) {
            if(i == mid) min = ptr->data;
            else if(min > ptr->data) min = ptr->data;
        }
        ptr = ptr->next;
        i++;
    }
    printf("The minimum value in the right array = %d\n", min);
}