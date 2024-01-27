// To convert queue into array format in Array

#include<stdio.h>
#include<stdlib.h>

int main() {
    int top = -1, rear = -1,  queue[20], arr[20], c, n;
    while(c != 4) {
        printf("\n[1]Enqueue\n[2]Dequeue\n[3]Convert to array\n[4]Exit\nEnter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            if((top <= rear) && (rear < 20)) {
                printf("Enter the value: ");
                scanf("%d", &queue[++rear]);
                printf("Element enqueued.\n");
            }
            else if((top == -1) && (rear == -1)) {
                printf("Enter the value: ");
                scanf("%d", &queue[++rear]);
                printf("Element enqueued.\n");
                top++;
            }
            else printf("Cannot able to enqueue an element.\n");
            break;
        case 2:
            if(top == rear) {
                top = -1;
                rear = -1;
                printf("Element dequeued.\n");
            }
            else if(top < rear) {
                top++;
                printf("Element dequeued.\n");
            }
            else printf("Cannot able to dequeue element.\n");
            break;
        case 3:
            n = 0;
            printf("The array is:\n");
            for(c = top + 1; c <= rear; c++) {
                arr[n] = queue[c];
                printf("%d ", arr[n++]);
            }
        default:
            break;
        }
    }
    return 0;
}

// [1]Enqueue
// [2]Dequeue
// [3]Convert to array
// [4]Exit
// Enter your choice: 1
// Enter the value: 1
// Element enqueued.

// [1]Enqueue
// [2]Dequeue
// [3]Convert to array
// [4]Exit
// Enter your choice: 1
// Enter the value: 2
// Element enqueued.

// [1]Enqueue
// [2]Dequeue
// [3]Convert to array
// [4]Exit
// Enter your choice: 1
// Enter the value: 3
// Element enqueued.

// [1]Enqueue
// [2]Dequeue
// [3]Convert to array
// [4]Exit
// Enter your choice: 2
// Element dequeued.

// [1]Enqueue
// [2]Dequeue
// [3]Convert to array
// [4]Exit
// Enter your choice: 3
// The array is:
// 2 3
// [1]Enqueue
// [2]Dequeue
// [3]Convert to array
// [4]Exit
// Enter your choice: 4