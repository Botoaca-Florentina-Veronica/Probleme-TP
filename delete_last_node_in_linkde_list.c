//delete the last node in a linked list(used 2 pointers here)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}node_t;


//functie pentru adaugarea unui element la sfarsitul listei
void add(node_t **head, int data)
{
    //cream un nod nou
    node_t *newnode;
    newnode=(node_t *)malloc(sizeof(node_t));
    newnode->data=data;
    newnode->link=NULL;

    //daca lista e goala, facem noul nod capul listei
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }

    //parcurgem lista pana la ultimul nod
    node_t *last;
    last=*head;
    while(last->link!=NULL)
    {
        last=last->link;
    }

    //adaugam noul nod la sfarsitul listei
    last->link=newnode;
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

node_t *delete_last_node(node_t *head)
{
    node_t *temp, *temp2;
    if(head==NULL)
    {
        printf("Linked list is empty!!");
        exit(1);
    }
    else if(head->link==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        temp=head;
        temp2=head;
        while(temp->link!=NULL)
        {
            temp2=temp;
            temp=temp->link;
        }
        temp2->link=NULL;
        free(temp);
        temp=NULL;
    }
    return head;
}


int main(void)
{
    node_t *head;
    head=NULL;
    add(&head, 3);
    add(&head, 4);
    add(&head, 5);
    printf("Lista initiala:\n");
    print_list(head);

    delete_last_node(head);
    printf("Lista cu ultimul element sters:\n");
    print_list(head);
    return 0;
}


//delete the last node in a linked list, using only one pointer

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

void delete_last_node(node_t *head)
{
    node_t *temp;
    temp=head;
    if(head==NULL)
    {
        printf("Linked list is empty!!");
        exit(1);
    }
    else if(head->link==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        while(temp->link->link!=NULL)
        {
            temp=temp->link;
        }
        free(temp->link);
        temp->link=NULL;   
    }
}

int main(void)
{
    node_t *head;
    printf("Initial linked list:\n");
    head=intoList(56);
    head->link=intoList(32);
    head->link->link=intoList(67);
    head->link->link->link=intoList(78);
    head->link->link->link->link=intoList(89);
    afisare(head);
    
    delete_last_node(head);
    printf("The linked list with the last node deleted:\n");
    afisare(head);
    return 0;
}
