/*Implementati si testati un program C care simuleaza o serie de evenimente asupra unei liste liniare, simplu inlantuite, astfel:
-primteste ca si unic parametru in linia de comanda un numar N si genereaza un numar de N numere naturale pseudeoaleatoare (X) 
cuprinse intre 1 si 200, efectuand urmatoarele operatii:
a) Daca X este divizibil cu 7 adauga la sfarsitul listei nodul avand informatia acel numar
b) Daca X este divizibil cu 3 adauga la inceputul listei nodul avand informatia acel numar
c) Daca x este 5 insereaza un nou nod pe pozitia 5 avand informatia numarul 5 
(daca nu exista inca destule noduri. atunci se va insera la sfarsit)
d) Daca este de 2 cifre sterge nodul de pe pozitia egala cu ultima cifra a lui X 
(daca nu exista destule noduri, se va sterge ultimul element)
-Afiseaza lista, dupa fiecare pas, si explica utilizatorului operatiilor efectuate*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node 
{
    int data;
    struct node* link;
}node_t;

node_t* head = NULL;

void printList() 
{
    node_t* current = head;
    printf("Lista: ");
    while (current != NULL) 
    {
        printf("%d ", current->data);
        current = current->link;
    }
    printf("\n");
}

void insertAtEnd(int data) 
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->link = NULL;
    if (head == NULL) 
    {
        head = newNode;
        return;
    }
    node_t *current = head;
    while (current->link!= NULL) 
    {
        current = current->link;
    }
    current->link = newNode;
}

void insertAtBeginning(int data) 
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->link = head;
    head = newNode;
}

void insertAtPosition(int position, int data) 
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->data = data;
    if (position == 1) 
    {
        newNode->link= head;
        head = newNode;
        return;
    }
    node_t *current = head;
    int i = 1;
    while (i < position - 1 && current != NULL) 
    {
        current = current->link;
        i++;
    }
    if (current == NULL) 
    {
        insertAtEnd(data);
        return;
    }
    newNode->link = current->link;
    current->link = newNode;
}

void deleteAtEnd() 
{
    if (head == NULL) 
    {
        return;
    }
    if (head->link == NULL) 
    {
        free(head);
        head = NULL;
        return;
    }
    node_t *current = head;
    while (current->link->link!= NULL) 
    {
        current = current->link;
    }
    free(current->link);
    current->link = NULL;
}

void deleteAtPosition(int position) 
{
    if (head == NULL) 
    {
        return;
    }
    if (position == 1) 
    {
        node_t *temp = head;
        head = head->link;
        free(temp);
        return;
    }
    node_t *current = head;
    int i = 1;
    while (i < position - 1 && current->link != NULL) 
    {
        current = current->link;
        i++;
    }
    if (current->link == NULL) 
    {
        deleteAtEnd();
        return;
    }
    node_t *temp = current->link;
    current->link = temp->link;
    free(temp);
}

int main(int argc, char* argv[]) 
{
    int i, n ,x;
    srand(time(0));
    if (argc != 2) 
    {
        printf("Trebuie sa introduceti un numar intreg ca si argument in linia de comanda.\n");
        return 0;
    }
    n= atoi(argv[1]);
    if (n <= 0) 
    {
        printf("Numarul introdus trebuie sa fie pozitiv si nenul.\n");
        return 0;
    }

for (i = 0; i < n; i++) 
{
    x = rand() % 200 + 1;
    printf("Generat numarul pseudoaleatoriu: %d\n", x);
    if (x % 7 == 0) 
    {
        insertAtEnd(x);
        printf("Inserat la sfarsitul listei nodul cu informatia %d\n", x);
    }
    if (x % 3 == 0) 
    {
        insertAtBeginning(x);
        printf("Inserat la inceputul listei nodul cu informatia %d\n", x);
    }
    if (x == 5) 
    {
        if (head == NULL) 
        {
            insertAtEnd(5);
            printf("Inserat la sfarsitul listei nodul cu informatia 5\n");
        } 
        else 
        {
            int length = 0;
            node_t *current = head;
            while (current != NULL) 
            {
                length++;
                current = current->link;
            }
            if (length < 5) 
            {
                insertAtEnd(5);
                printf("Inserat la sfarsitul listei nodul cu informatia 5\n");
            } 
            else 
            {
                insertAtPosition(5, 5);
                printf("Inserat pe pozitia 5 nodul cu informatia 5\n");
            }
        }
    }
    if (x >= 10 && x <= 99) 
    {
        int position = x % 10 + 1;
        deleteAtPosition(position);
        printf("Sters nodul de pe pozitia %d\n", position);
    }
    printList();
}
return 0;
}
