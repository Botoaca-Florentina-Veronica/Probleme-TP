//insertion at the beggining of a double linked list
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
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
        printf("%d ",  ptr->data);
        ptr=ptr->next;
    }
}

void add_node_at_beggining(node_t **head, int data)
{
    node_t *newnode;
    newnode = (node_t *)malloc(sizeof(node_t));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=*head;

    if(*head!=NULL)
    {
        (*head)->prev=newnode;
    }

    *head=newnode;
}

int main(void)
{
    node_t *head=NULL;
    add_node_at_beggining(&head, 3);
    add_node_at_beggining(&head, 4);
    add_node_at_beggining(&head, 5);
    add_node_at_beggining(&head, 6);
    add_node_at_beggining(&head, 7);
    print_list(head);
    return 0;
}
