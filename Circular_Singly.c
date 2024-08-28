#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void insertionAtBegin(struct node *tail,int value)
{
    struct node *new_node=malloc(sizeof(struct node));
    new_node->data=value;
    new_node->link=tail->link;
    tail->link=new_node;
}

void insertionAtEnd(struct node **tail,int value)
{
    struct node *new_node=malloc(sizeof(struct node));
    struct node *ptr=*tail;
    new_node->data=value;
    new_node->link=ptr->link;
    ptr->link=new_node;
    *tail=new_node;
}
void display(struct node *tail)
{
    
    struct node *ptr=tail;
    do
    {
        printf("%d -> ", ptr->data);
        
        ptr=ptr->link;
    }while (ptr!=tail);
    printf("head %d \n",tail->data);
    
}

int main()
{
    struct node *tail=malloc(sizeof(struct node));
    tail->data=47;
    tail->link=tail;
    
    
    insertionAtBegin(tail,45);
    insertionAtBegin(tail,54);
    insertionAtBegin(tail,80);
    insertionAtBegin(tail,90);
    display(tail);
    
    insertionAtEnd(&tail,10);
    insertionAtEnd(&tail,20);
    display(tail);
}
