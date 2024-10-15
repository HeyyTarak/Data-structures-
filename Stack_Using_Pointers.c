#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

// Function to push an element onto the stack
void push(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

// Function to pop an element from the stack
int pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = top->data;
    Node* temp = top;
    top = top->next;
    free(temp);
    return data;
}


int peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1; 
    }
    return top->data;
}

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Top element: %d\n", peek());

    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

    printf("Is the stack empty? %d\n", isEmpty());

    return 0;
}
