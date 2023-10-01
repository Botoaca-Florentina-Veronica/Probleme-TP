//how to add a node at the beginning of the list
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

    //acum parcurg lista pentru a printa toate elementele
    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->link;
    }
}

void add_node_at_first(node_t **head, int data)
{
    node_t *newnode;
    newnode=(node_t *)malloc(sizeof(node_t));
    newnode->data=data;
    newnode->link=*head;

    *head=newnode;
}

/*
->void are la final un return node_t ceva, deci ca parametru voi avea **head
->la node_t *functie la parametru am *head
*/
int main(void)
{
    node_t *head=NULL;
    add_node_at_first(&head, 1);
    add_node_at_first(&head, 2);
    add_node_at_first(&head, 3);
    print_list(head);
    return 0;
}
