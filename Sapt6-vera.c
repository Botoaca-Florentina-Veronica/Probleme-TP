#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
} Node;

typedef struct
{
    Node* top;
    int size;
} Stack;


Stack* createStack()
{
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

int isEmpty(Stack* stack)
{
    return (stack->top == NULL);
}

void push(Stack* stack, int data)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

int pop(Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

int peek(Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->top->data;
}

int size(Stack* stack)
{
    return stack->size;
}

void destroyStack(Stack* stack)
{
    Node* current = stack->top;
    while (current != NULL)
    {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}
int main() 
{
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top element is %d\n", peek(stack));
    printf("Stack size is %d\n", size(stack));

    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));

    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }

    destroyStack(stack);
    return 0;
}


