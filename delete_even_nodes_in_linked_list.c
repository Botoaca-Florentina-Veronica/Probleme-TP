//delete the even nodes in a linked list
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
        printf("Eroare la alocarea dinamica a memoriei pt nod!");
        exit(1);
    }
    
    if(*head==NULL)
    {
        //daca lista este goala atunci noul element va deveni chiar capul listei
        *head=newnode;
        return;
    }

    node_t *last_node;
    last_node=*head;
    while(last_node->link!=NULL)
    {
        last_node=last_node->link;
    }
    //daca ies din bucla while, atunci inseamna ca am parcurs toata lista pana la finalul ei
    //deci acum vreau ca ultimul element al listei sa pointeze spre adresa noului nod
    //de aici si linia de cod:
    last_node->link=newnode;
}

node_t *delete_nodes(node_t *head)
{
    node_t *curr, *prev;
    curr=head;
    prev=NULL;

    while(curr!=NULL)
    {
        if(curr->data%2==0)
        {
            if(prev==NULL)
            {
                //daca chiar capul listei este par atunci il vom sterge
                //intai vom schimba adresa la care pointer ul head  "pointeaza" pentru ca daca o facem după
                //riscam sa pierdem informatia pe care acesta o contine
                //si astfel sa pierdem legaturile cu celelalte elemente ale listei
                head=curr->link;
                free(curr);  //aici eliberam memoria accesata de pointerul curent (care e si par)
                curr=head; //*1.
            }
            else
            //daca ajungem aici inseamna ca avem si alte noduri pare inafara de capul listei
            {
                prev->link=curr->link;
                free(curr);    //eliberez memoria, nu sterg intrgul nod!!!
                curr=prev->link;  // *2.   aici ca si la *1 am scris aceasta linie de cod fiindca pointerul meu curr trebuie
                // mereu schimbat la urmatorul, nu sa stea pe loc
            }
        }
        else
        //daca ajungem aici inseamna ca am trecut cu bine de posibilitatea de a avea numere pare in lista
        //deci nu ne mai ramane decat sa o parcurgem mai departe
        {
            prev=curr; //nu vrem sa lasam pointerul anterior sa fie egal cu null, trebuie updatat, la fel si curr dupa cum urmeaza:
            curr=curr->link;  //ce am incercat sa facem la *1 si *2
        }
    }
    return head;
}

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

    printf("Lista dupa stergeri:\n");
    head=delete_nodes(head);
    print_list(head);
    return 0;
}
