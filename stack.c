#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// 1. Push
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
        printf("%d pushed into stack\n", value);
    }
}

// 2. Pop
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d popped from stack\n", stack[top--]);
    }
}

// 3. Peek
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element = %d\n", stack[top]);
    }
}

// 4. Display
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// 5. isEmpty
void isEmpty() {
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    display();
    peek();

    pop();
    display();

    isEmpty();

    return 0;
}
