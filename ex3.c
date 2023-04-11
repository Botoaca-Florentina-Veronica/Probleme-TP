//Write a C program to sort a given stack using another stack.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 1000

int stack_array[MAX_SIZE];
int sorted_stack[MAX_SIZE];
int top=-1;

int isFull(top)
{
    return(top==MAX_SIZE-1);
}

int isEmpty(top)
{
    return(top==-1);
}


void push(int data)
{
    if(isFull(top))
    {
        printf("Stack is full!");
        exit(1);
    }
    top=top+1;
    stack_array[top]=data;
}

int pop()
{
    int data;
    if(isEmpty(top))
    {
        printf("Stack is empty!");
        exit(1);
    }
    data=stack_array[top];
    top=top-1;
    return data;
}

void afisare()
{
    int i;
    for(i=0; i<=top; i++)
    {
        printf("%d ", stack_array[i]);
    }
    printf("\n");
}

void sort_stack()
{
    int temp;
    int sorted_top = -1;
    while(top!=-1)
    {
        temp=pop();
        while(sorted_top != -1 && sorted_stack[sorted_top] < temp)
        {
            push(sorted_stack[sorted_top]);
            sorted_top--;
        }
        sorted_top++;
        sorted_stack[sorted_top]=temp;
    }
    while(sorted_top!=-1)
    {
        push(sorted_stack[sorted_top]);
        sorted_top--;
    }
}

int main(void)
{
    printf("Elementele din stiva:\n");
    push(9);
    push(7);
    push(3);
    push(6);
    push(2);
    push(5);
    printf("\n");
    afisare();


    sort_stack();
    printf("\n");
    afisare();
    return 0;
}
