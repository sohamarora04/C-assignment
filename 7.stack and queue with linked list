#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Stack operations
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto stack\n", data);
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = (*top)->data;
    struct Node* temp = *top;
    *top = (*top)->next;
    free(temp);
    printf("Popped %d from stack\n", data);
    return data;
}

// Queue operations
void enqueue(struct Node** rear, struct Node** front, int data) {
    struct Node* newNode = createNode(data);
    if (*rear == NULL) {
        *rear = *front = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("Enqueued %d into queue\n", data);
}

int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = (*front)->data;
    struct Node* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;  // If queue becomes empty
    }
    free(temp);
    printf("Dequeued %d from queue\n", data);
    return data;
}

// Display function to display the stack or queue
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* stack = NULL;  // Stack top pointer
    struct Node* front = NULL;  // Queue front pointer
    struct Node* rear = NULL;   // Queue rear pointer
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push to Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue to Queue\n");
        printf("5. Dequeue from Queue\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push onto stack: ");
                scanf("%d", &data);
                push(&stack, data);
                break;

            case 2:
                pop(&stack);
                break;

            case 3:
                printf("Stack: ");
                display(stack);
                break;

            case 4:
                printf("Enter data to enqueue into queue: ");
                scanf("%d", &data);
                enqueue(&rear, &front, data);
                break;

            case 5:
                dequeue(&front, &rear);
                break;

            case 6:
                printf("Queue: ");
                display(front);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
