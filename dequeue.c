#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *front = NULL, *rear = NULL;

void insertFront(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = front;

    if (front == NULL)
        front = rear = newnode;
    else {
        front->prev = newnode;
        front = newnode;
    }
}

void insertRear(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = rear;

    if (rear == NULL)
        front = rear = newnode;
    else {
        rear->next = newnode;
        rear = newnode;
    }
}

void deleteFront() {
    if (front == NULL) {
        printf("Deque Underflow\n");
        return;
    }

    struct node *temp = front;
    printf("Deleted: %d\n", temp->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;
    else
        front->prev = NULL;

    free(temp);
}

void deleteRear() {
    if (rear == NULL) {
        printf("Deque Underflow\n");
        return;
    }

    struct node *temp = rear;
    printf("Deleted: %d\n", temp->data);

    rear = rear->prev;

    if (rear == NULL)
        front = NULL;
    else
        rear->next = NULL;

    free(temp);
}

void display() {
    struct node *temp = front;

    if (front == NULL) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertFront(10);
    insertRear(20);
    insertFront(5);
    insertRear(30);

    display();

    deleteFront();
    deleteRear();

    display();

    return 0;
}