#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct circularqueue {
    int size;
    int front;
    int rear;
    int *arr;
};

bool isFull(struct circularqueue *q) {
    return (q->rear + 1) % q->size == q->front;
}

bool isEmpty(struct circularqueue *q) {
    return q->rear == -1;
}

void addToQueue(struct circularqueue *q, int val) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
    } else {
        if (q->rear == -1) {
            q->front = q->rear = 0;
        } else {
            q->rear = (q->rear + 1) % q->size;
        }
        q->arr[q->rear] = val;
    }
}

int removeFromQueue(struct circularqueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int val = q->arr[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % q->size;
        }
        return val;
    }
}

void showQueue(struct circularqueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    int i = q->front;
    printf("Queue elements: ");
    while (i != q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("%d\n", q->arr[i]);
}

int main() {
    struct circularqueue q;
    q.size = 5;  
    q.front = q.rear = -1; 
    q.arr = (int*)malloc(q.size * sizeof(int));

    int choice, value;

    while (1) {
        printf("\n1. Add to Queue\n2. Remove from Queue\n3. Show Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                addToQueue(&q, value);
                break;
            case 2:
                printf("Removed value: %d\n", removeFromQueue(&q));
                break;
            case 3:
                showQueue(&q);
                break;
            case 4:
                free(q.arr);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
