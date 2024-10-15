#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

// Function to enqueue an element
void enqueue(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to dequeue an element
int dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1; 
    }

    int data = front->data;
    Node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    return data;
}

int peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}

int isEmpty() {
    return front == NULL;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Front element: %d\n", peek());

    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());

    printf("Is the queue empty? %d\n", isEmpty());

    return 0;
}
