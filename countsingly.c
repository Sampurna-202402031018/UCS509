#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int n)
{
    struct node *newNode, *temp;
    int i, data;

    for (i = 1; i <= n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }
}

int count()
{
    struct node *temp = head;
    int c = 0;

    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }

    return c;
}

int main()
{
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    create(n);

    printf("Number of elements = %d\n", count());

    return 0;
} 