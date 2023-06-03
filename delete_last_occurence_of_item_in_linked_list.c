//Delete the last occurrence of an item from a linked list. 
//So if the item is 7 and the list is [1,3,7,4,3,7,2], the result is [1,3,7,4,3,2].#include<stdio.h>
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
        printf("%d\n", ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}

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

    //parcurg fiecare element al listei pana la ultimul, apoi imi adaug noul nod
    node_t *last_node;
    last_node=*head;
    while(last_node->link!=NULL)
    {
        last_node=last_node->link;
    }
    last_node->link=newnode;
}

node_t *delete_last_occurence(node_t *head, int num)
{
    node_t *curr = head;
    node_t *prev = NULL;
    node_t *last_occurrence = NULL;
    node_t *prev_occurrence = NULL;

    if (curr == NULL)
    {
        printf("Linked list is already empty!");
        exit(1);
    }
    while (curr != NULL)
    {
        if (curr->data == num)
        {
            last_occurrence = curr;
            prev_occurrence = prev;
        }
        prev = curr;
        curr = curr->link;
    }
    if (last_occurrence == NULL)
    {
        printf("Last occurrence of %d not found in the linked list.", num);
        return head;
    }
    if (prev_occurrence == NULL)
    {
        head = head->link;
    }
    else
    {
        prev_occurrence->link = last_occurrence->link;
    }

    free(last_occurrence);
    return head;
}

int main(void)
{
    node_t *head;
    head=NULL;
    add(&head, 1);
    add(&head, 2);
    add(&head, 3);
    add(&head, 4);
    add(&head, 2);

    printf("Lista initiala este:\n");
    print_list(head);

    printf("Lista cu ultima aparitie a numarului 2 stearsa este:\n");
    delete_last_occurence(head, 2);
    print_list(head);
    return 0;
}
