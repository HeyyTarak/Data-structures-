#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

// Function to enqueue an element
void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
}

// Function to dequeue an element
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return data;
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1; 
    }
    return queue[front];
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
