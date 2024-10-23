#include <stdio.h>
#include <stdlib.h>

#define MAX 10  
 
struct Stack {
    int arr[MAX];
    int top;
};
  
void push(struct Stack *s, int value);
int pop(struct Stack *s);
int isEmpty(struct Stack *s);
int isFull(struct Stack *s);
int peek(struct Stack *s);
void display(struct Stack *s);

int main() {
    struct Stack s;
    s.top = -1; 
    int choice, value;

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if empty\n");
        printf("6. Check if full\n");
        printf("7. Exit\n");
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
                value = peek(&s);
                if (value != -1) {
                    printf("Top value: %d\n", value);
                }
                break;
            case 4:
                display(&s);
                break;
            case 5:
                if (isEmpty(&s)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 6:
                if (isFull(&s)) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
int isEmpty(struct Stack *s) {
    return s->top == -1;
}
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Unable to push %d\n", value);
    } else {
        s->arr[++s->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}
 
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Unable to pop from an empty stack.\n");
        return -1;  
    } else {
        return s->arr[s->top--];
    }
}
void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}
 
int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. No top element.\n");
        return -1; 
    } else {
        return s->arr[s->top];
    }
}
 

 
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}
 
