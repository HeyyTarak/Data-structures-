
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void insertionAtBegin(struct node **head,int value)
{
    struct node *ptr=*head;
    struct node *temp=malloc(sizeof(struct node));
    temp->data=value;
    temp->link=ptr;
    *head=temp;
}

void insertionAtEnd(struct node *head,int value)
{
    struct node *ptr=head;
    struct node *temp=malloc(sizeof(struct node));
    temp->data=value;
    while(ptr->link!=NULL)
        ptr=ptr->link;
    temp->link=NULL;
    ptr->link=temp;
}

void insertionAtCertain(struct node *head,int value,int position)
{
    struct node *ptr=head;
    struct node *temp=malloc(sizeof(struct node));
    temp->data=value;
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


void count_nodes(struct node *head)
{
    int count=0;
    if(head==NULL)
        printf("There are no nodes");
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    
    }
    printf("The total number of nodes are: %d\n",count);
    
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
    struct node *head;
    head=malloc(sizeof(struct node));
    printf("Enter elements into your node 1: ");
    scanf("%d",&head->data);
    head->link=NULL;
    
    //you can also make dynamic with scanf
    printf("Insertion at Begining: \n");
    insertionAtBegin(&head,10);
    insertionAtBegin(&head,20);
    insertionAtBegin(&head,30);
    count_nodes(head);
    display(head);

    printf("Insertion at Ending: \n");
    insertionAtEnd(head,60);
    insertionAtEnd(head,70);
    insertionAtEnd(head,80);
    count_nodes(head);
    display(head);

    printf("insertion at specific: \n");
    insertionAtCertain(head,25,45);
    count_nodes(head);
    display(head);

    printf("Deletion at Begin: \n");
    deletionAtBegin(&head);
    count_nodes(head);
    display(head);

    printf("Deletion at End: \n");
    deletionAtEnd(head);
    count_nodes(head);
    display(head);
}
