#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

// Check if stack is empty
int isEmpty()
{
    if(top == NULL)
        return 1;
    return 0;
}

// Push
void push(int value)
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

// Pop
void pop()
{
    struct node *temp;

    if(isEmpty())
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("Deleted Element = %d\n", top->data);

    top = top->next;
    free(temp);
}

// Peek
void peek()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Top Element = %d\n", top->data);
}

// Display
void display()
{
    struct node *temp;

    if(isEmpty())
    {
        printf("Stack is Empty\n");
        return;
    }

    temp = top;

    printf("Stack Elements:\n");
    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    peek();

    pop();

    display();

    if(isEmpty())
        printf("Stack is Empty\n");
    else
        printf("Stack is Not Empty\n");

    return 0;
}