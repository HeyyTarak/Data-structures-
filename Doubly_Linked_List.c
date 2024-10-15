
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void insertionAtBegin(struct node **head,int value)
{
    struct node *ptr=*head;
    struct node *temp=malloc(sizeof(struct node));
    temp->data=value;
    temp->next=ptr;
    temp->prev=NULL;
    ptr->prev=temp;
    *head=temp;
    
}

void insertionAtEnd(struct node *head,int value)
{
    struct node *ptr=head;
    struct node *temp=malloc(sizeof(struct node));
    temp->data=value;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    temp->next=NULL;
    ptr->next=temp;
    temp->prev=ptr;
}

void insertionAtCertain(struct node *head, int value, int position) 
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = value;

    // Traverse the list until reaching the desired position or the end
    for (int i = 1; i < position - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }

    // Insert the new node
    temp->next = ptr->next;
    temp->prev = ptr;
    if (ptr->next != NULL) {
        ptr->next->prev = temp;
    }
    ptr->next = temp;
}

void deletionAtBegin(struct node **head)
{   
    struct node *ptr=*head;
    *head=ptr->next;
    ptr->next->prev=NULL;
    free(ptr);
}

void deletionAtEnd(struct node *head)
{
    struct node *ptr = head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;   
    }
    ptr->prev->next=NULL;
    free(ptr); 
}

void display(struct node *head)
{
    if(head==NULL)
        printf("No content");
    struct node *ptr=head;
    printf("Forward: ");
    while (ptr!=NULL)
    {
        printf("%d -> ", ptr->data);
        if(ptr->next==NULL)
        {
            break;
        }
        ptr=ptr->next;
    }
    printf("NULL \n");
    
    printf("Backward: ");
    while(ptr!=NULL)
    {
        printf("%d -> ",ptr->data);
        ptr=ptr->prev;
    }
    printf("NULL \n");
    
}
int main() {
    struct node *head;
    head=malloc(sizeof(struct node));
    printf("Enter elements into your node 1: ");
    scanf("%d",&head->data);
    head->next=NULL;
    head->prev=NULL;
    
    //you can also make dynamic with scanf
    printf("Insertion at Begining: \n");
    insertionAtBegin(&head,10);
    insertionAtBegin(&head,20);
    insertionAtBegin(&head,30);
    display(head);
    
    printf("Insertion at Ending: \n");
    insertionAtEnd(head,60);
    insertionAtEnd(head,70);
    insertionAtEnd(head,80);
    display(head);
    
    printf("insertion at specific: \n");
    insertionAtCertain(head,25,45);
    display(head);
    
    printf("Deletion at Begin: \n");
    deletionAtBegin(&head);
    display(head);
    
    printf("Deletion at End: \n");
    deletionAtEnd(head);
    display(head);
}
