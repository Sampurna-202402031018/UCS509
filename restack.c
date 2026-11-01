#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Reverse stack
void reverse()
{
    int i, temp;

    for(i = 0; i <= top / 2; i++)
    {
        temp = stack[i];
        stack[i] = stack[top - i];
        stack[top - i] = temp;
    }
}

// Display stack
void display()
{
    int i;

    if(top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for(i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);

    printf("Before Reverse:\n");
    display();

    reverse();

    printf("After Reverse:\n");
    display();

    return 0;
}