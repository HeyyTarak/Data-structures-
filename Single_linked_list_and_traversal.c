#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
    
    
};

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
    printf("%d",count);
    
}
int main() {
    struct node *head;
    head=malloc(sizeof(struct node));
    printf("Enter elements into your node 1: ");
    scanf("%d",&head->data);
    head->link=NULL;
    
    struct node *current;
    current=malloc(sizeof(struct node));
    printf("Enter elements into your node 2: ");
    scanf("%d",&current->data);
    head->link=current;
    current->link=NULL;
    
    current=malloc(sizeof(struct node));
    printf("Enter elements into your node 3: ");
    scanf("%d",&current->data);
    current->link=NULL;
    head->link->link=current;
    
    count_nodes(head);
    
}