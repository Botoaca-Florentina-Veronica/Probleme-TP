//Delete all occurrences of an item from a linked list. 
//So if the item is 7 and the list is [1,3,7,4,3,7,2], the result is [1,3,4,3,2]
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


node_t *delete_specific_item(node_t *head, int num)
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
        if (curr->data == num) 
        {
            if (prev == NULL) 
            {
                // Deleting the first node if it is the specific item
                head = curr->link;
                free(curr);
                curr = head;
            } 
            else 
            {
                // Deleting a specific item, other than the first one
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


void add(node_t **head, int data)
{
    node_t *newnode;
    newnode=(node_t *)malloc(sizeof(node_t));
    newnode->data=data;
    newnode->link=NULL;

    node_t *last_node;
    last_node=*head;
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }

    //parcurg fiecare element al listei pana la final pentru a adauga noul element
    while(last_node->link!=NULL)
    {
        last_node=last_node->link;
    }
    last_node->link=newnode;
}


int main(void)
{
    node_t *head=NULL;
    add(&head, 7);
    add(&head, 7);
    add(&head, 7);
    add(&head, 7);
    add(&head, 3);
    add(&head, 7);
    add(&head, 7);
    printf("Lista initiala este:\n");
    print_list(head);


    // Function call
    head=delete_specific_item(head, 7);
	if (head==NULL)
	{
        printf("\nNo element present in the Linked list\n");
    }
	else 
    {
		printf("\nLinked List after Deletion is:\n");
		print_list(head);
	}
    return 0;
}
