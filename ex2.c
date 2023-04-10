//Write a C program that accepts a string and reverse it using a stack.
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

int isFull(top)
{
    return(top == MAX_SIZE - 1);
}

int isEmpty(top)
{
    return(top == -1);
}

void push(char data) 
{
    if(isFull(top))
    {
        printf("Overflow stack!\n");
        return;
    }
    top++;
    stack[top] = data;
}

char pop() 
{
    if(isEmpty(top))
    {
        printf("Empty Stack!\n");
        return '\0';
    }
    char data = stack[top];
    top--;
    return data;
}
void reverse_string(char *str) 
{
    int i;
    int len = strlen(str);
    for (i=0; i < len; i++) 
    {
        push(str[i]);
    }
    for (i=0; i < len; i++) 
    {
        str[i] = pop();
    }
}
int main(void) 
{
    char text[MAX_SIZE];
    printf("Input a string: ");
    fgets(text, MAX_SIZE, stdin);
    text[strcspn(text, "\n")] = '\0';
    reverse_string(text);
    printf("Reversed string using a stack is: %s\n", text);
    return 0;
}
