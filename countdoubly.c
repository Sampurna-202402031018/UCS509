#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Create and insert at end
void insert(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Count nodes
int countNodes() {
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    printf("Number of elements = %d\n", countNodes());

    return 0;
}