//Count the number of times a particular item occurs in a linked list. 
//So if the item is 7 and the list is [1,3,7,4,3,7,2], the result is 2. 
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
    node_t *last_node;
    last_node=*head;
    
    //parcurg fiecare element al listei pana ajung la ultimul, dupa adaug noul nod
    while(last_node->link!=NULL)
    {
        last_node=last_node->link;
    }
    last_node->link=newnode;
}


int count_number_of_occurences(node_t *head, int num)
{
    node_t *ptr;
    ptr=head;
    if(head==NULL)
    {
        printf("Linked list is already empty!");
        exit(1);
    }
    int count=0;
    while(ptr!=NULL)
    {
        if(ptr->data==num)
        {
            count++;
        }
        ptr=ptr->link;
    }
    return count;
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

    printf("Numarul de aparitii al numarului 2 este:\n");
    int count=0;
    count = count_number_of_occurences(head, 2);
    printf("%d\n",count);
    return 0;
}
