//c program that prints all items of a single linked list on the screen

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

int main()
{
   node_t *head = intoList(9); //inserting elements into a list
   head->link = intoList(76);
   head->link->link = intoList(13);
   head->link->link->link = intoList(24);
   head->link->link->link->link = intoList(55);
   head->link->link->link->link->link = intoList(109);
   printf("\n");
   print_list(head);
   return 0;
}
