#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at End
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

// Find Minimum and Maximum
void findMinMax() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    int min = head->data;
    int max = head->data;

    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->data < min)
            min = temp->data;

        if (temp->data > max)
            max = temp->data;

        temp = temp->next;
    }

    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);
}

int main() {
    insert(25);
    insert(10);
    insert(40);
    insert(5);
    insert(30);

    findMinMax();

    return 0;
}