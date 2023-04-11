//Write a C program to find the maximum element in a stack.
/*Expected Output:

Current stack elements:
5 2 1 6 8 
Maximum element: 8

After removing two elements:
Current stack elements:
5 2 1 
Maximum element: 5

After adding one element:
Current stack elements:
5 2 1 10 
Maximum element: 10*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 1000

int stack_array[MAX_SIZE];
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
    return data;    //tinem minte elementul pe care il stergem
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

int el_maxim()
{
    int max=-1;
    int temp;
    while(top!=-1)
    {
        temp=pop();
        if(temp>max)
        {
            max=temp;
        }
    }
    return max;
}
int main(void)
{
    printf("Stiva initiala:\n");
    push(5);
    push(12);
    push(3);
    push(4);
    afisare();
    
    int max;
    max=el_maxim();
    printf("\nmax este egal cu: %d\n", max);
    return 0;
}
