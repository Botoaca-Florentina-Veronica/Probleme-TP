/*Write a C program to implement a stack and accept some numeric values. Remove the number whose value is the minimum on the stack. Go to the editor
Expected Output:

Elements of the stack:
Stack: 7 4 5 2 3 1 
Minimum value of the said stack: 1
Elements of the stack after removing the said minimum value:
Stack: 7 4 5 2 3 
Minimum value of the said stack: 2
Elements of the stack after removing the said minimum value:
Stack: 7 4 5 3 
Minimum value of the said stack: 3
Elements of the stack after removing the said minimum value:
Stack: 7 4 5 
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 1000

int stack_array[MAX_SIZE];
int stack2[MAX_SIZE];
int top=-1;

int isFull(int top)
{
    return(top==MAX_SIZE-1);
}

int isEmpty(int top)
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
    top++;
    stack_array[top]=data;
}

int pop()
{
    if(isEmpty(top))
    {
        printf("Stack is empty!");
        exit(1);
    }
    int data;
    data=stack_array[top];
    top--;
    return data;
}

int getMin() 
{
    int i;
    int min = stack_array[0];
    for (i=1; i<=top; i++) 
    {
        if (stack_array[i] < min) 
        {
            min = stack_array[i];
        }
    }
    return min;
}

void removeMin() 
{
    int min = getMin();
    int i, count = 0;
    for (i=0; i<=top; i++) 
    {
        if (stack_array[i] != min) 
        {
            stack_array[count] = stack_array[i];
            count++;
        }
    }
    top=count-1;
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


int main(void)
{
    printf("Initial stack:\n");
    push(1);
    push(2);
    push(3);
    afisare();
    printf("\n");
    

    removeMin();
    afisare();
    return 0;
}
