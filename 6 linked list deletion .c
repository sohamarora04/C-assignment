#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int data;
    struct Node* next;
};
 
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
 
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
 
void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}
 
void deleteElement(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
 
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
 
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    } 
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    } 
    prev->next = temp->next;
    free(temp);
} 
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
 
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
 
int main() {
    struct Node* head = NULL;
    while(1)
    {

        printf("choose the options from the given menu \n 1. insert at last\n 2. delete head \n 3. delete tail \n 4. delete ele \n 5.display \n 6. exit \n");
        int choice=0;
        int data=0;
        int key=0;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            
            scanf("%d",&data);
            append(&head,data);
            break;
        case 2:
            deleteFirst(&head);
            break;
        case 3:
            deleteLast(&head);
            break;
        case 4:
            
        printf("\n");
            scanf("%d",&key);
            deleteElement(&head, key);
            break;
        case 5:
        
        printf("\n");
             displayList(head);
             break;
        case 6:
        printf("\n");
            exit(0);
        default:
            break;
        }





    }

}
