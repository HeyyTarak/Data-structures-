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
    
    new_node->data=value;
    new_node->link=(*tail)->link;
    (*tail)->link=new_node;
    *tail=new_node;
}

void insertionAtCertain(struct node *tail,int value,int position)
{
    struct node *ptr=tail->link;
    struct node *temp=malloc(sizeof(struct node));
    do
    {
        ptr=ptr->link;
    }while(ptr!=tail->link&&ptr->data!=position);
    temp->data=value;
    temp->link=ptr->link;
    ptr->link=temp;
    
    
}
void deletionAtBegin(struct node *tail) {
    if (tail->link == tail) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = tail->link;
    tail->link = tail->link->link;
    free(temp);
}

void deletionAtEnd(struct node **tail) {
    if (tail->link == tail) {
        printf("List is empty\n");
        return;
    }
    struct node *ptr = tail->link;
    while (ptr->link != tail->link) {
        ptr = ptr->link;
    }
    ptr->link = tail->link;
    free(*tail);
    *tail = ptr;
}

void display(struct node *tail)
{
    
    struct node *ptr=tail->link;
    do
    {
        printf("%d -> ", ptr->data);
        
        ptr=ptr->link;
    }while (ptr!=tail->link);
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
    
    insertionAtCertain(tail,1,54);
    display(tail);

    deletionAtBegin(tail);
    display(tail);

    deletionAtEnd(&tail);
    display(tail);

}
