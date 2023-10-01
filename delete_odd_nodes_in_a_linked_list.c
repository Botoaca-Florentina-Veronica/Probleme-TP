//how to add a node at the begininng of the list
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
    if(head==NULL)
    {
        printf("Linked list is empty!");
        exit(1);
    }

    //acum parcurg lista pentru a printa toate elementele
    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->link;
    }
}

void add_last_node(node_t **head, int data)
{
    node_t *newnode;
    newnode=(node_t *)malloc(sizeof(node_t));
    newnode->data=data;
    newnode->link=NULL;

    if(newnode==NULL)
    {
        printf("Eroare la alocarea dinamica a noului nod!");
        exit(1);
    }

    if(*head==NULL)
    {
        //daca lista e goala, noul nod introdus va deveni chiar capul listei
        *head=newnode;
        return;
    }

    node_t *last_node;
    last_node=*head;
    while(last_node->link!=NULL)
    {
        last_node=last_node->link;
    }
    last_node->link=newnode;
}

node_t *delete_odd_elements(node_t *head)
{
    node_t *curr, *prev;
    curr=head;
    prev=NULL;

    if(head==NULL)
    {
        printf("Linked list is alreay empty!");
        exit(1);
    }

    while(curr!=NULL)
    {
        if(curr->data%2==1)
        {
            if(prev==NULL)
            {
                //inseamna ca ma aflu la capul listei, care din intamplare e chiar impar, asa ca nu imi mai ramane decat sa il sterg
                //btw in caz ca nu e clar, ma aflu la capul listei fiindca nu am un nod anterior(prev==NULL)
                head=curr->link;
                free(curr);
                curr=head;
                //aici nu am curr=curr->link pt ca am eliberat deja memoria alocata pentru pointerul curent(curr),
                //deci nu mai poate fi accesata
            }
            else
            {
                //adica am alt nod impar inafara de capul listei
                prev->link=curr->link;
                free(curr);
                curr=prev->link;
            }
        }
        else
        {
            //adica nu am dat de niciun nod impar, yey
            prev=curr;
            curr=curr->link;
            //adica parcurg lista normal, dar trebuie schimbate nodurile cu cele imediat urmatoare la fiecare iteratie
        }
    }
    return head;
}


/*
->void are la final un return node_t ceva, deci ca parametru voi avea **head
->la node_t *functie la parametru am *head
*/

int main(void)
{
    node_t *head=NULL;
    printf("Lista initiala:\n");
    add_last_node(&head, 1);
    add_last_node(&head, 2);
    add_last_node(&head, 3);
    add_last_node(&head, 4);
    add_last_node(&head, 5);
    print_list(head);

    printf("\nLista dupa stergerea elementelor impare:\n");
    head=delete_odd_elements(head);
    print_list(head);
    return 0;
}
