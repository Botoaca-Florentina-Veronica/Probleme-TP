//C program to delete even nodes

//met1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

    //daca lista e goala, atunci noul meu nod devine capul listei
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }

    //acum parcurg lista pana la ultimul element, dupa care imi adaug noul nod
    node_t *last_node;
    last_node=*head;
    while(last_node->link!=NULL)
    {
        last_node=last_node->link;
    }
    last_node->link=newnode;
}


node_t *delete_even_nodes(node_t *head)
{
    node_t *temp, *temp2;
    temp = head;
    temp2 = NULL;

    // Verific dacă primul nod este par și îl șterg
    while (temp != NULL && temp->data % 2 == 0)
    {
        head = temp->link;
        free(temp);
        temp = head;
    }

    // Parcurg restul listei și șterg nodurile pare
    while (temp != NULL)
    {
        while (temp != NULL && temp->data % 2 != 0)
        {
            temp2 = temp;
            temp = temp->link;
        }

        if (temp == NULL)
            break;

        temp2->link = temp->link;
        free(temp);
        temp = temp2->link;
    }

    return head;
}


void add_first_node(node_t **head, int data)
{
    node_t *newnode;
    newnode=(node_t *)malloc(sizeof(node_t));
    newnode->data=data;
    newnode->link=*head;

    *head=newnode;
}


int main(void)
{
    node_t *head;
    head=NULL;
    add_last_node(&head, 1);
    add_last_node(&head, 2);
    add_last_node(&head, 3);
    add_last_node(&head, 4);
    add_first_node(&head, 0);
    print_list(head);

    head=delete_even_nodes(head);
    print_list(head);
    return 0;
}


//met 2
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

    //parcurgem fiecare element pana la finalul listei
    node_t *last_node;
    last_node=*head;
    while(last_node->link!=NULL)
    {
        last_node=last_node->link;
    }
    last_node->link=newnode;
}

// Function to delete even nodes from the linked list
node_t *delete_even_node(node_t *head)
{
    if (head == NULL)
    {
        printf("Linked list is already empty!");
        exit(1);
    }

    node_t *curr = head;
    node_t *prev = NULL;

    while (curr != NULL) 
    {
        if (curr->data % 2 == 0) 
        {
            if (prev == NULL) 
            {
                // Deleting the first node if it is even
                head = curr->link;
                free(curr);
                curr = head;
            } 
            else 
            {
                // Deleting an even node, other than the first node
                prev->link = curr->link;
                free(curr);
                curr = prev->link;
            }
        } 
        else 
        {
            prev = curr;
            curr = curr->link;
        }
    }
    return head;
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
    add(&head, 4);
    printf("Lista initial este:\n");
    print_list(head);

    printf("Lista cu elementele pare sterse este:\n");
    delete_even_node(head);
    print_list(head);
    return 0;
}
