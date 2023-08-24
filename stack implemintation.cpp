#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
// Structure to represent the stack
struct Stack {
    int data[MAX_SIZE];
    int top;
};
// Initialize an empty stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}
// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
// Check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}
// Push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->data[++stack->top] = value;
}
// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack->data[stack->top--];
}
// Peek at the top element of the stack without popping
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->data[stack->top];
}
int main() {
    struct Stack stack;
    initializeStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("Top element: %d\n", peek(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Top element: %d\n", peek(&stack));
    return 0;
}
