#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Create Node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

// Insert at Beginning
void insertBegin(int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;

    head = newNode;
}

// Insert at End
void insertEnd(int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;
}

// Insert at Position
void insertPosition(int data, int pos) {
    if (pos == 1) {
        insertBegin(data);
        return;
    }

    struct Node *temp = head;
    int i;

    for (i = 1; i < pos - 1; i++) {
        temp = temp->next;

        if (temp == head) {
            printf("Invalid Position\n");
            return;
        }
    }

    struct Node *newNode = createNode(data);

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

// Display
void display() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    struct Node *temp = head;

    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(HEAD)\n");
}

int main() {
    insertBegin(20);
    insertBegin(10);

    insertEnd(40);
    insertEnd(50);

    insertPosition(30, 3);

    display();

    return 0;
}