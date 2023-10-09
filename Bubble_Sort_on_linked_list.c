// C program to implement Bubble Sort on singly linked list 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}node_t;

void print_list(node_t *head)
{
    node_t *ptr;
    ptr=head;
    if(head==NULL)
    {
        printf("Linked list is empty!");
        exit(1);
    }
    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->link;
    }
}


void add_last_element(node_t **head, int data)
{
    node_t *newnode;
    newnode=(node_t *)malloc(sizeof(node_t));
    newnode->data=data;
    newnode->link=NULL;

    if(*head==NULL)
    {
        //daca lista e goala, atunci noul element introdus in lista noastra devine chiar capul listei
        *head=newnode;
        return;
    }

    node_t *last_node;
    last_node=*head;

    while(last_node->link!=NULL)
    {
        //parcurg lista pana la ultimul element, dupa care atunci cand ies din bucla voi lega noul nod la final
        last_node=last_node->link;
    }
    last_node->link=newnode;
}

//function to swap two nodes in a linked list
void swap(node_t *a, node_t *b)
{
    int temp;
    temp=a->data;
    a->data=b->data;
    b->data=temp;
}

//function to perform bubblesort on the linked list
void bubbleSort(node_t *head)
{
    int swapped;
    node_t *ptr1, *ptr2;
    ptr2=NULL;

    //verificam mereu daca lista e goala!
    if(head==NULL)
    {
        printf("Linked list is empty!");
    }

    do
    {
        swapped = 0;
        ptr1=head;
        while(ptr1->link!=ptr2)
        {
            //compar informatia unui nod cu cea a vecinului sau
            if(ptr1->data > ptr1->link->data)
            {
                //daca am 30 > 21 fac swap-ul
                //nu pun ptr1->data si ptr->link->data fiindca vreau sa schimb nodurile cu totul nu doar cu numerele 
                //continute de acestea!
                swap(ptr1, ptr1->link);
                swapped = 1;
            }
            //trec la urmatorul nod pentru a urma sa il compar
            ptr1=ptr1->link;
        }
        ptr2=ptr1;
    } 
    while (swapped);
    
}

int main(void)
{
    node_t *head=NULL;
    add_last_element(&head, 5);
    add_last_element(&head, 4);
    add_last_element(&head, 23);
    add_last_element(&head, 2);
    add_last_element(&head, 11);
    print_list(head);
    printf("\n");

    //acum printam noua lista ordonata crescator
    bubbleSort(head);
    print_list(head);
    return 0;
}
