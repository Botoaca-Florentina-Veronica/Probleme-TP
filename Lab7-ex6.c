//6. Se citesc numere intregi dintr-un fisier text si se creeaza o lista cu aceste elemente. 
//Sa se creeze 2 liste care sa contina in ordine elementele din fisier, una elementele pare, iar cealalta pe cele impare.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node
{
    int data;
    struct node *link;
}node_t;

// functia de adaugare a unui nod la inceputul listei
void insert_at_beggining(node_t **head, int data)
{
    node_t *newnode;
    newnode=(node_t *)malloc(sizeof(node_t));
    newnode->data=data;
    newnode->link=*head;
    *head=newnode;
}

// functia de separare a listei initiale in 2 liste separate cu elemente pare si impare
void separate_list(node_t *head, node_t **even_head, node_t **odd_head)
{
    node_t *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->data%2==0)
        {
            insert_at_beggining(even_head, ptr->data);
        }
        else
        {
            insert_at_beggining(odd_head, ptr->data);
        }
        ptr=ptr->link;
    }
}

void print_list(node_t *head)
{
    node_t *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}


int main(void)
{
    node_t *head=NULL;
    node_t *even_head=NULL;
    node_t *odd_head=NULL;

    
    FILE *f1;
    char fname[100]="verasmechera.txt";
    f1=fopen(fname, "r");
    if(f1==NULL)
    {
        printf("Eroare de scriere in fisier!!!");
        exit(1);
    }
    int num;
    while(fscanf(f1, "%d", &num)!=EOF)
    {
        insert_at_beggining(&head, num);
    }
    fclose(f1);

    //afisarea listei initiale
    printf("Lista initiala:");
    print_list(head);

    // initializarea listelor even_head si odd_head
    even_head = NULL;
    odd_head = NULL;

    // separarea listei initiale in 2 liste separate cu elemente pare si impare
    separate_list(head, &even_head, &odd_head);
    // afisarea listei cu elemente pare
    printf("Lista cu elemente pare: ");
    print_list(even_head);

    // afisarea listei cu elemente impare
    printf("Lista cu elemente impare: ");
    print_list(odd_head);

    return 0;
}
