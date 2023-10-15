//insert a node at the end of a double linked list
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node_t;

void print_list(node_t *head)
{
    node_t *ptr;
    ptr=head;
    if(head==NULL)
    {
        printf("Double linked list is empty!");
        exit(1);
    }
    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
}

void add_last_node(node_t **head, int data)
{
    node_t *newnode;
    newnode=(node_t *)malloc(sizeof(node_t));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;

    //daca lista e goala, atunci noul nod devine chiar capul listei
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }

    //traversam intreaga lista pentru a ajunge la ultimul node
    node_t *last_node;
    last_node = *head;
    while(last_node->next!=NULL)
    {
        last_node=last_node->next;
    }

    last_node->next=newnode;
    newnode->prev=last_node;   
}


int main(void)
{
    node_t *head =NULL;
    add_last_node(&head, 1);
    add_last_node(&head, 2);
    add_last_node(&head, 3);
    add_last_node(&head, 4);
    add_last_node(&head, 5);
    print_list(head);
    return 0;
}
