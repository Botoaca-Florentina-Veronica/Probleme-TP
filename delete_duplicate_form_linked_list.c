//C Program to Remove Duplicates from a Linked List
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

node_t* delete_duplicates(node_t* head)
{
    node_t* current, *next, *temp;
    current = head;

    if (head == NULL)
    {
        printf("Linked list is already empty!");
        return NULL;
    }

    while (current != NULL)
    {
        next = current;
        while (next->link != NULL)
        {
            if (current->data == next->link->data)
            {
                temp = next->link;
                next->link = next->link->link;
                free(temp);
            }
            else
            {
                next = next->link; //la fiecare iteratie vom schimba nodul cu urmatorul
            }
            //aici nu ies din bucla while pana nu compar primul nod cu fiecare element din lista
            //adica daca am nodul curent cu informatia 1, pointerul meu next va parcurge lista pana la final
            //si va efectua conditia if de fiecare data pana iese adevarata(adica comparam 1 cu toate informatiile 
            //nodurilor din lista sa vedem daca ii gasim pereche)
            //daca nu avem duplicate cu primul nod dupa acest prim ciclu de verificari
            //atunci vom iesi din bucla si vom trece la urmatorul nod, dupa care repetam pasii
        }
        current = current->link;
    }

    //intuiesc ca avem O(n^2)

    return head;
}


int main(void)
{
    node_t *head=NULL;
    printf("Lista initiala:\n");
    add_last_node(&head, 1);
    add_last_node(&head, 2);
    add_last_node(&head, 3);
    add_last_node(&head, 2);
    print_list(head);

    printf("\nLista fara duplicate:\n");
    head=delete_duplicates(head);
    print_list(head);
    return 0;
}
