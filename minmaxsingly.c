#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at end
void insert(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Find Minimum and Maximum
void findMinMax() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    int min = head->data;
    int max = head->data;

    struct Node *temp = head->next;

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