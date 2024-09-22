#include <stdio.h>
#include<stdlib.h>
#define MAX 100

int stack[MAX];
int top=-1;

int isFull()
{
    return top==MAX-1;
}
int isEmpty()
{
    return top==-1;
}
void push()
{
    if(isFull())
    {
        printf("You cant push stack is already Full");
        return;
    }
    printf("Enter the element you want to Push into the stack\n");
    scanf("%d",&stack[++top]);
    printf("Your elemend is pushed\n");
}
int pop()
{
    if(isEmpty())
    {
        printf("You can pop as stack is empty");
        return -1;
    }
    int po=stack[top--];
    printf("yeah element is popped\n");
}
void display()
{
    if(isEmpty())
    {
        printf("You can pop as stack is empty");
        return;
    }
    for(int i=0;i<top;i++)
    {
        printf("%d -> ",stack[i]);
    }
    printf("top\n");
}
void peek()
{
    if(isEmpty())
    {
        printf("Your stack is empty dude");
        return;
    }
    printf("top element in your stack is %d\n",stack[top]);
}

int main() {
    int ch;
    printf("Welcome to the program of Stack \nChoose your option\n");
    
    while(1)
    {   printf("1: To Push in to the Stack\n2: To Pop the element in the stack\n3: To view Top element in your Stack\n4: To Display all elements in your stack\n5: To exit the Program\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:peek();
            break;
            case 4:display();
            break;
            case 5:printf("Thank you! Visit Again");
            break;
            default:printf("Choose the correct Option");
            
        }
    }

    return 0;
}
