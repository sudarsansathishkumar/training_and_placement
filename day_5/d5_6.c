// To make a billing program in college canteen apply dynamic structure

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item {
    char name[20];
    float price;
    struct item *next;
}*head;

struct bill {
    char stdname[20];
    int stdid, n;
    struct item *items;
};

int main() {
    struct bill s;
    struct item *ptr, *prev;
    s.n = 0;
    char c[20] = "";
    int i;
    float p, total;
    printf("Enter the name: ");
    scanf("%s", s.stdname);
    printf("Enter the ID: ");
    scanf("%d", &s.stdid);
    printf("Enter exit for item name to exit.\n");
    while(strcmp(c, "exit")) {
        printf("Enter the item name: ");
        scanf("%s", c);
        if(strcmp(c, "exit")) {
            printf("Enter the price: ");
            scanf("%f", &p);
            ptr = (struct item *)malloc(sizeof(struct item));
            strcpy(ptr->name, c);
            ptr->price = p;
            ptr->next = NULL;
            if(head == NULL) head = ptr;
            else prev->next = ptr;
            prev = ptr;
            s.n++;
        }
    }
    printf("\n---------------------------------\n");
    printf("Name: %s\n", s.stdname);
    printf("ID: %d\n", s.stdid);
    ptr = head;
    while(ptr != NULL) {
        printf("%s\t%.2f\n", ptr->name, ptr->price);
        total += ptr->price;
        ptr = ptr->next;
    }
    printf("Total\t%.2f\n", total);
    return 0;
}

// Enter the name: aaa
// Enter the ID: 100
// Enter exit for item name to exit.
// Enter the item name: a
// Enter the price: 10
// Enter the item name: b
// Enter the price: 20.3
// Enter the item name: c
// Enter the price: 50.2
// Enter the item name: exit

// ---------------------------------
// Name: aaa
// ID: 100
// a       10.00
// b       20.30
// c       50.20
// Total   80.50