#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at end
void insert(int data)
{
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
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
}

// Delete a node by value
void deleteNode(int key)
{
    struct node *temp = head, *prev = NULL;

    if(temp != NULL && temp->data == key)
    {
        head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Node not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Display list
void display()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
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

    printf("Linked List:\n");
    display();

    deleteNode(30);

    printf("After Deletion:\n");
    display();

    return 0;
}