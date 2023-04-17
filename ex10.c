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
    if(newnode==NULL)
    {
        printf("Eroare la alocarea dinamica!!");
        exit(1);
    }
    newnode->data=data;
    newnode->link=NULL;
    return newnode;
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

node_t *remove_num(int num, node_t *head)
{
    node_t *current_node;
    current_node = head;

    node_t *prev_node;
    while(current_node != NULL)
    {
        if(current_node->data==num)
        {
            if(current_node==head)
            {
                head=current_node->link;
            }
            else
            {
                prev_node->link=current_node->link;
            }
        }
        prev_node = current_node;
        current_node =current_node->link;
    }
    return head;
}

void delete(int pos, node_t *head)
{
    node_t *ptr;
    ptr=head;
    int i;
    if(pos==0)
    {
        printf("\nElement deleted is %d\n", ptr->data);
        ptr=ptr->link;
        ptr->link=NULL;
        free(ptr);
    }
    else
    {
        for(i=1; i<pos-1; i++)
        {
            ptr=ptr->link;
        }
        node_t *del;
        del=ptr->link;

        ptr->link=ptr->link->link;
        printf("\nElement deleted is %d\n", del->data);

        del->link=NULL;
        free(del);
    }
    printf("\nUpdated linked list is: \n");
    print_list(head);
    return;
}

int count_of_nodes(node_t *head)
{
    int count=0;
    if(head==NULL)
    {
        printf("Linked list is empty!!");
    }
    node_t *ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    return count;
}


void Insert(node_t *head, int index, int num)
{
    node_t *ptr;
    int i;
    if (index<0 || index>count_of_nodes(head))
    {
        return;
    }
    ptr = (node_t *)malloc(sizeof (node_t));
    ptr->data = num;
    if (index == 0)
    {
        ptr->link = intoList(num);
        ptr=intoList(num);
    }
    else
    {
        for (i=1; i<index-1; i++)
        {
            head=head->link;
        }
        ptr->link = head->link;
        head->link = ptr;
    }
}


int main(void)
{
    node_t *head;
    head=intoList(3);
    head->link=intoList(4);
    head->link->link=intoList(43);
    head->link->link->link=intoList(41);
    print_list(head);

    Insert(head, 2, 13);
    print_list(head);
    return 0;
}
