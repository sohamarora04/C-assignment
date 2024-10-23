#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Maximum size of the stack

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Function prototypes
void push(struct Stack *s, int value);
int pop(struct Stack *s);
void display(struct Stack *s);

int main() {
    struct Stack s;
    s.top = -1; // Initialize top
    int choice, value;

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                display(&s);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Push function
void push(struct Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow! Unable to push %d\n", value);
    } else {
        s->arr[++s->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Pop function
int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow! Unable to pop from an empty stack.\n");
        return -1; // Return -1 if stack is empty
    } else {
        return s->arr[s->top--];
    }
}

// Display function
void display(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}
