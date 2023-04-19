//delete the first node in a linked list
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
    while(ptr!=NULL)
    {
        printf("%d\n", ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}

node_t *delete_first_node(node_t *head)
{
    node_t *temp;
    if(head==NULL)
    {
        printf("Linked list is empty!!");
        exit(1);
    }
    else
    {
        temp=head;
        head=head->link;
        free(temp);
        temp=NULL;
    }   
    return head;
}

int main(void)
{
    node_t *head;
    printf("Initial linked list is:\n");
    head=intoList(69);
    head->link=intoList(32);
    head->link->link=intoList(56);
    head->link->link->link=intoList(21);
    afisare(head);

    printf("The new liked list with the first element deleted:\n");
    head=delete_first_node(head);
    afisare(head);
    return 0;
}
