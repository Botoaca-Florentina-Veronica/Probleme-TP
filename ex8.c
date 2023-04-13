//c program to search an element in a single linked list

#include <stdio.h>
#include <stdlib.h>
//structure of a node
typedef struct node 
{
   int data;
   struct node *link;
}node_t;


node_t *intoList(int data) 
{
   node_t *newnode = (node_t *)malloc(sizeof(node_t));
   newnode->data = data;
   newnode->link = NULL;
   return newnode;
}

//funtion to display list
void print_list(node_t * head) 
{
    node_t * ptr;
    ptr=head;
    while (ptr != NULL) 
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}

int search_element(int key, node_t *head)
{
    int i;      //reprezinta indexul elementului la care ne aflam
    i=1;
    node_t *newnode;
    newnode=head;
    while(newnode!=NULL && newnode->data!=key)
    {
        i++;
        newnode=newnode->link;
    }
    if(newnode!=NULL)
    {
        return i;
    }
    else
    {
        return -1;
    }
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


int main(void)
{
   int i;
   node_t *head = intoList(9); //inserting elements into a list
   head->link = intoList(76);
   head->link->link = intoList(13);
   head->link->link->link = intoList(24);
   head->link->link->link->link = intoList(55);
   head->link->link->link->link->link = intoList(109);
   printf("\n");
   print_list(head);

   i=search_element(24, head);
   if(i>=0)
   {
    printf("Element found at position %d\n", i);
   }
   else
   {
    printf("Element not found!");
   }

   printf("The number of nodes in the linked list below is:%d ", count_of_nodes(head));
   return 0;
}
