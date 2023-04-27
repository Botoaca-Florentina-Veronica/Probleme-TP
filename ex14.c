/*Implementati si testati un program C care simuleaza o serie de evenimente asupra unei liste liniare, simplu inlantuite, astfel:
-primteste ca si unic parametru in linia de comanda un numar N si genereaza un numar de N numere naturale pseudeoaleatoare (X) 
cuprinse intre 1 si 200, efectuand urmatoarele operatii:
a) Daca X este divizibil cu 7 adauga la sfarsitul listei nodul avand informatia acel numar
b) Daca X este divizibil cu 3 adauga la inceputul listei nodul avand informatia acel numar
c) Daca x este 5 insereaza un nou nod pe pozitia 5 avand informatia numarul 5 
(daca nu exista inca destule noduri. atunci se va insera la sfarsit)
d) Daca este de 2 cifre sterge nodul de pe pozitia egala cu ultima cifra a lui X 
(daca nu exista destule noduri, se va sterge ultimul element)
-Afiseaza lista, dupa fiecare pas, si explica utilizatorului operatiilor efectuate
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node 
{
    int data;
    struct node* link;
}node_t;

void add_node_start(node_t *head, int data) 
{
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->data = data;
    new_node->link = head;
    head = new_node;
}

void insert_node(node_t *head, int data, int pos) 
{
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->data = data;
    if (head == NULL) 
    {
        new_node->link = NULL;
        head = new_node;
    } 
    else 
    {
        node_t *curr = head;
        node_t *prev = NULL;
        int i = 1;
        while (i < pos && curr->link != NULL) 
        {
            prev = curr;
            curr = curr->link;
            i++;
        }
        if (prev == NULL) 
        {
            new_node->link = curr;
            head = new_node;
        } 
        else 
        {
            new_node->link = curr;
            prev->link = new_node;
        }
    }
}

void delete_node(node_t *head, int pos) 
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
}

void add_node_end(node_t *head, int data) 
{
    node_t *ptr;
    node_t *temp;
    ptr=head;

    temp=(node_t *)malloc(sizeof(node_t));
    temp->data=data;
    temp->link=NULL;

    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
}

void print_list(node_t *head) 
{
    printf("Lista curenta: ");
    node_t *ptr;
    ptr = head;
    while (ptr != NULL) 
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

int main(int argc, char* argv[]) 
{
    int i, x, n;
    node_t *head = NULL;
    srand(time(NULL));
    if (argc != 2) 
    {
        printf("Folosire: ./lista N\n");
        exit(1);
    }
    n = atoi(argv[1]);

    for (i=0; i<n; i++) 
    {
        x = rand() % 200 + 1;
        printf("Generat numarul %d\n", x);
        if (x % 7 == 0) 
        {
            add_node_end(head, x);
            printf("Adaugat %d la sfarsitul listei\n", x);
        }
        if (x % 3 == 0) 
        {
            add_node_start(head, x);
            printf("Adaugat %d la inceputul listei\n", x);
        }
        if (x == 5) 
        {
            insert_node(head, 5, 5);
            printf("Inserat %d pe pozitia 5 (daca exista destule noduri)\n", x);
        }
        if (x > 9 && x < 100) 
        {
        int pos = x % 10;
        delete_node(head, pos);
        printf("Sters nodul de pe pozitia %d (daca exista destule noduri)\n", pos);
        }
    }
    print_list(head);
    return 0;  
}
