//adding an element at the end of a linked list
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}node_t;

node_t *intoList(int data)
{
    node_t *newnode=(node_t *)malloc(sizeof(node_t));
    newnode->data=data;
    newnode->link=NULL;
    return newnode;
}

void afisare(node_t *head)
{
    node_t *ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("Eroare la pointer ul ptr!!");
        exit(1);
    }
    while(ptr!=NULL)
    {
        printf("%d\n", ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}

void add_last_node(node_t *head, int data)
{
    node_t *ptr;
    node_t *temp;
    ptr=head;

    temp=(node_t *)malloc(sizeof(node_t));
    temp->data=data;
    temp->link=NULL;


    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
    printf("New list becomes:\n");
    afisare(head);
}

int main(void)
{
    node_t *head;

    printf("Initial list:\n");
    head=intoList(34);
    head->link=intoList(21);
    head->link->link=intoList(42);
    head->link->link->link=intoList(56);
    afisare(head);

    add_last_node(head, 89);
    return 0;
}
