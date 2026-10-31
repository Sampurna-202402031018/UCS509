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

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return;
    }

    temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = head;
}

// Delete a node by value
void deleteNode(int key)
{
    struct node *temp = head, *prev = NULL;

    if(head == NULL)
        return;

    // Single node case
    if(head->data == key && head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    // Delete first node
    if(head->data == key)
    {
        temp = head;

        while(temp->next != head)
            temp = temp->next;

        temp->next = head->next;
        head = head->next;
        free(temp->next);
        return;
    }

    temp = head;
    do
    {
        prev = temp;
        temp = temp->next;
    } while(temp != head && temp->data != key);

    if(temp == head)
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
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("(head)\n");
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    printf("Circular Linked List:\n");
    display();

    deleteNode(30);

    printf("After Deletion:\n");
    display();

    return 0;
}