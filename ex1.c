//Write a C program to check a stack is full or not using an array with push and pop operations.
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 3

// Function to create an empty stack
int *createStack() 
{
    int *stack = (int*) malloc(MAX_SIZE * sizeof(int));
    return stack;
}

// Check if the stack is empty
int isEmpty(int top) 
{
    return (top == -1);
}

// Check if the stack is full
int isFull(int top) 
{
    return (top == MAX_SIZE - 1);
}

// Function to push an element to the stack
void push(int *stack, int *top, int data) 
{
    if (isFull(*top)) 
    {
        printf("Stack is full!\n");
        exit(1);
    }
    (*top)++;
    stack[*top] = data;
}

// Function to pop an element from the stack
int pop(int *stack, int *top) 
{
    if (isEmpty(*top)) 
    {
        printf("Stack is empty!\n");
        exit(1);
    }
    (*top)--;
    return stack[*top];
}


int main(void) 
{
    int *stack = createStack();
    int result, top1=-1, i;
    printf("\nStack size: %d\n",MAX_SIZE);
    push(stack, &top1, 10);
    push(stack, &top1, 20);
    push(stack, &top1, 30);
    printf("\nOriginal Stack: ");
    for (i=0; i <= top1; i++) 
    {
        printf("%d ", stack[i]);
    } 
    printf("\n");
    result = isFull(top1);
    if (result==1)
    {
        printf("Stack is full!");
    }
    else
    {
        printf("Stack is not full!");
    }
    free(stack);
    return 0;
}
