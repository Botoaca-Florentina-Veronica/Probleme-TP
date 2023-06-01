//C Program to Remove Duplicates from a Linked List
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}node_t;

void add(node_t **head, int data)
{
    node_t *newnode;
    newnode=(node_t *)malloc(sizeof(node_t));
    newnode->data=data;
    newnode->link=NULL;

    if(*head==NULL)
    {
        *head=newnode;
        return;
    }

    node_t *last_node;
    last_node=*head;
    //parcurg fiecare element din lista
    while(last_node->link!=NULL)
    {
        last_node=last_node->link;
    }
    //adaugam noul nod la sfarsitul listei
    last_node->link=newnode;
}

void remove_duplicates(node_t *head)
{
    node_t *ptr = head;
    while (ptr != NULL && ptr->link != NULL)
    {
        node_t *ptr2 = ptr->link;
        while (ptr2->data == ptr->data)
        {
            ptr->link = ptr2->link;
            free(ptr2);
        }
        ptr = ptr->link;
    }
}

void print_list(node_t *head)
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

int main(void)
{
    node_t *head;
    head=NULL;
    add(&head, 1);
    add(&head, 2);
    add(&head, 3);
    add(&head, 3);
    add(&head, 4);
    add(&head, 4);
    printf("Lista initiala:\n");
    print_list(head);

    printf("Lista cu duplicatele sterse:\n");
    remove_duplicates(head);
    print_list(head);
    return 0;
}
