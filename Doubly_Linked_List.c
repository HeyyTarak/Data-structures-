#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void insertionAtBegin(struct node **head, int value) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->next = *head;
    temp->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = temp;
    }
    *head = temp;
}

void insertionAtEnd(struct node **head, int value) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if (*head == NULL) {
        temp->prev = NULL;
        *head = temp;
        return;
    }

    struct node *ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
}

void insertionAtCertain(struct node *head, int value, int position) {
    if (position <= 0) {
        printf("Invalid position!\n");
        return;
    }

    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = value;

    for (int i = 1; i < position - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Position out of bounds!\n");
        free(temp);
        return;
    }

    temp->next = ptr->next;
    temp->prev = ptr;
    if (ptr->next != NULL) {
        ptr->next->prev = temp;
    }
    ptr->next = temp;
}

void deletionAtBegin(struct node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *ptr = *head;
    *head = ptr->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(ptr);
}

void deletionAtEnd(struct node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    if (ptr->prev != NULL) {
        ptr->prev->next = NULL;
    } else {
        *head = NULL;  // Only one element in the list
    }
    free(ptr);
}

void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *ptr = head;
    printf("Forward: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");

    // Print backward
    if (head != NULL) {
        while (head->next != NULL) {
            head = head->next;
        }
    }
    printf("Backward: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->prev;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;

    printf("Insertion at Beginning:\n");
    insertionAtBegin(&head, 10);
    insertionAtBegin(&head, 20);
    insertionAtBegin(&head, 30);
    display(head);

    printf("Insertion at End:\n");
    insertionAtEnd(&head, 60);
    insertionAtEnd(&head, 70);
    insertionAtEnd(&head, 80);
    display(head);

    printf("Insertion at Specific Position:\n");
    insertionAtCertain(head, 25, 3);
    display(head);

    printf("Deletion at Beginning:\n");
    deletionAtBegin(&head);
    display(head);

    printf("Deletion at End:\n");
    deletionAtEnd(&head);
    display(head);

    return 0;
}
