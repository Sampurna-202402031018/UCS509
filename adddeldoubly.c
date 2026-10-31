#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Insert at end
void insert(int data)
{
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
        return;
    }

    temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

// Delete a node by value
void deleteNode(int key)
{
    struct node *temp = head;

    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Node not found\n");
        return;
    }

    if(temp == head)
    {
        head = temp->next;
        if(head != NULL)
            head->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;

        if(temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
}

// Display list
void display()
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    printf("Doubly Linked List:\n");
    display();

    deleteNode(30);

    printf("After Deletion:\n");
    display();

    return 0;
}