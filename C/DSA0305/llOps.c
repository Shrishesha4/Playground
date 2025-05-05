#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) return newNode;
    
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

struct Node* deleteNode(struct Node* head, int value) {
    struct Node *current = head, *prev = NULL;
    
    if (current != NULL && current->data == value) {
        head = current->next;
        free(current);
        return head;
    }
    
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) return head;
    
    prev->next = current->next;
    free(current);
    return head;
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtBeginning(head, 5);
    
    printf("Original list: ");
    display(head);
    
    head = deleteNode(head, 20);
    
    printf("After deleting 20: ");
    display(head);
    
    return 0;
}