#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// Check if queue is empty
int isEmpty()
{
    if(front == NULL)
        return 1;
    return 0;
}

// Enqueue
void enqueue(int value)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(isEmpty())
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

// Dequeue
void dequeue()
{
    struct node *temp;

    if(isEmpty())
    {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;
    printf("Deleted Element = %d\n", front->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

// Display queue
void display()
{
    struct node *temp;

    if(isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    temp = front;

    printf("Queue Elements: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    if(isEmpty())
        printf("Queue is Empty\n");
    else
        printf("Queue is Not Empty\n");

    return 0;
}