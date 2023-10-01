/*Delete the last occurrence of an item from a linked list. 
So if the item is 7 and the list is [1,3,7,4,3,7,2], the result is [1,3,7,4,3,2].*/
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
    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}

void add_last_node(node_t **head, int data)
{
    node_t *newnode;
    newnode=(node_t *)malloc(sizeof(node_t));
    newnode->data=data;
    newnode->link=NULL;

    if(newnode==NULL)
    {
        printf("Eroare la alocarea dinamica a memoriei pt noul nod!");
        exit(1);
    }

    //daca lista e goala, noul nod devine capul listei
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }

    //acum, parcurgem lista pana la ultimul element, dupa care adaugam noul nod
    node_t *last_node;
    last_node=*head;
    while(last_node->link!=NULL)
    {
        last_node=last_node->link;
    }
    last_node->link=newnode;
}

void add_first_node(node_t **head, int data)
{
    node_t *newnode;
    newnode=(node_t *)malloc(sizeof(node_t));
    newnode->data=data;
    newnode->link=*head;

    *head=newnode;
}

node_t *delete_last_occurence_of_item(node_t *head, int num)
{
    node_t *temp = head;
    node_t *last_occurrence = NULL;
    node_t *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            last_occurrence = temp;
        }
        temp = temp->link;
    }
    // Dacă nu s-a găsit nicio apariție a elementului, se returnează lista nemodificată
    if (last_occurrence == NULL)
    {
        return head;
    }
    temp = head;
    while (temp != NULL && temp != last_occurrence)
    {
        prev = temp;
        temp = temp->link;
    }
    if (prev != NULL)
    {
        prev->link = last_occurrence->link;
    }
    else
    {
        head = last_occurrence->link;
    }
    free(last_occurrence);
    return head;
}


int main(void)
{
    node_t *head;
    head=NULL;
    add_last_node(&head, 3);
    add_last_node(&head, 2);
    add_last_node(&head, 3);
    add_last_node(&head, 4);
    add_last_node(&head, 3);
    print_list(head);

    head=delete_last_occurence_of_item(head, 3);
    print_list(head);
    return 0;
}
