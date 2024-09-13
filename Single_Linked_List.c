
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void insertionAtBegin(struct node **head)
{
    struct node *ptr=*head;
    struct node *temp=malloc(sizeof(struct node));
    printf("Enter the Values you want to Insert At the begin: ");
    scanf("%d",&temp->data);
    temp->link=ptr;
    *head=temp;
}

void insertionAtEnd(struct node *head)
{
    struct node *ptr=head;
    struct node *temp=malloc(sizeof(struct node));
    printf("Enter the Values you want to Insert At the End: ");
    scanf("%d",&temp->data);
    while(ptr->link!=NULL)
        ptr=ptr->link;
    temp->link=NULL;
    ptr->link=temp;
}

void insertionAtCertain(struct node *head)
{   
    int position;
    struct node *ptr=head;
    struct node *temp=malloc(sizeof(struct node));
    printf("Enter the Values you want to Insert At the Certain node: ");
    scanf("%d",&temp->data);
    printf("At which position you want to insert enter the node Data: ");
    scanf("%d",&position);
    while(ptr->link!=NULL)
    {   
        if(ptr->data==position)
            break;
        ptr=ptr->link;
    }
    temp->link=ptr->link;
    ptr->link=temp;

}

void deletionAtBegin(struct node **head)
{   
    struct node *ptr=*head;
    *head=ptr->link;
    free(ptr);
}

void deletionAtEnd(struct node *head)
{
    struct node *ptr = head;
    struct node *prev = NULL;

    while(ptr->link != NULL)
    {
        prev = ptr;
        ptr = ptr->link;
    }

    prev->link = NULL;
    
    free(ptr); 
}


void search(struct node *head)
{   
    int value;
    printf("Enter the Values you want to Search: ");
    scanf("%d",&value);
    if(head==NULL)
        printf("There are no nodes");
    struct node *ptr=head;
    
    while(ptr!=NULL && ptr->data==value)
    {
        printf("Element is found in the List");
        ptr=ptr->link;
    
    }
    
    
}

void display(struct node *head)
{
    if(head==NULL)
        printf("No content");
    struct node *ptr=head;
    while (ptr!=NULL)
    {
        printf("%d -> ", ptr->data);
        ptr=ptr->link;
    }
    printf("NULL \n");
    
}
int main() {
    struct node *head;int ch;
    head=malloc(sizeof(struct node));
    printf("Enter elements into your node 1: ");
    scanf("%d",&head->data);
    head->link=NULL;
    while (1)
    {
    printf("Insertion at Begin choose 1\nInsertion at End choose 2\nInsertion at a certain node choose 3\nDeletion at Begin choose 4\nDeletion at End choose 5\nTo search Element choose 6\nTo print the list choose 7\nTo Exit the program choose 8\n");
    scanf("%d",&ch);
    switch(ch)
        {
            case 1:insertionAtBegin(&head);
            break;
            case 2:insertionAtEnd(head);
            break;
            case 3:insertionAtCertain(head);
            break;
            case 4:deletionAtBegin(&head);
            break;
            case 5:deletionAtEnd(head);
            break;
            case 6:search(head);
            break;
            case 7:display(head);
            break;
            case 8: exit(0);
        }
    
    }    
}
