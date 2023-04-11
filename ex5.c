/*Write a C program to calculate the average value of the stack elements.
Expected Output:

Elements of the stack:
6 4 2 5 3 1 
Average of the said stack values: 3.50

Popped value: 6

Elements of the stack:
4 2 5 3 1 
Average of the said stack values: 3.00
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 1000

int stack_array[MAX_SIZE];
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

double average_function()
{
    double average, temp, sum=0, k=0;
    while(top!=-1)
    {
        temp=pop();
        sum=sum+temp;
        k++;
    }
    average=sum/k;
    return average;
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
    printf("The initial stack is:\n");
    push(1);
    push(10);
    push(45);
    push(2);
    afisare();
    printf("\n");

    double average;
    average=average_function();
    printf("The average of the integers below is:%.2f\n", average);
    return 0;
}
