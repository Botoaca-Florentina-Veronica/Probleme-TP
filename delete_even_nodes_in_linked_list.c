//C program to delete even nodes
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
