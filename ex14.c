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
//varianta vera

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

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

void adaugare_element_final(node_t *head, int data)
{
    node_t *newnode=(node_t *)malloc(sizeof(node_t));
    newnode->data=data;
    newnode->link=NULL;


    if(head==NULL)
    {
        head=newnode;
        return;
    }
    node_t *ptr;
    ptr=head;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=newnode;
}

void adaugare_element_initial(node_t *head, int data)
{
    node_t *newnode=(node_t *)malloc(sizeof(node_t));
    newnode->data=data;
    newnode->link=head;
    head=data;
}

int main(int argc, char *argv[])
{
    node_t *head;
    printf("Lista initiala:\n");
    head=intoList(34);
    head->link=intoList(45);
    head->link->link=intoList(56);
    afisare(head);
    if(argc!=2)
    {
        printf("Numar incorect de argumente in linie de comanda!!");
        exit(1);
    }


    //a)
    printf("Lista cu elementul final divizibil cu 7")
    if(atoi(argv[1])%7==0)
    {
        adaugare_element_final(head, atoi(argv[1]));
    }
    afisare(head);

    //b)
    printf("Lista cu elementul initial divizibil cu 3")''
    if(atoi(argv[2]))
    return 0;
}

