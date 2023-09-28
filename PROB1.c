/*
    Sa se creeze o lista simplu inlantuita de articole cu structura:cod produs un camp numeric de maximum 4 caractere, 
denumirea produsului un camp alfanumeric de maximum 15 caractere, unitatea de masura un camp de 2 caractere 
alfabetice(bc,kg,mp,ml,mc,l,hl, etc.) si pretul produsului, in ordinea introducerii de la tastatura si apoi 
sa se afiseze pe ecran lista.
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    char cod_produs[20];
    char denumire[20];
    char unitate_masura[20];
    int pret;
    struct node *link;
}node_t;


void afisare_lista(node_t *head)
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
        printf("Cod produs: %s\n, Denumire produs: %s\n, Unitate de masura: %s\n, pret produs: %d\n", 
        ptr->cod_produs, ptr->denumire, ptr->unitate_masura, ptr->pret);
        ptr=ptr->link;
    }
}


void inserare_element_final(node_t **head, char cod_produs[20], char denumire[20], char unitate_masura[20], int pret)
{
    node_t *newnode;
    newnode=(node_t *)malloc(sizeof(node_t));
    strncpy(newnode->cod_produs, cod_produs, 20);
    strncpy(newnode->denumire, denumire, 20);
    strncpy(newnode->unitate_masura, unitate_masura, 20);
    newnode->pret=pret;
    newnode->link=NULL;

    if(*head==NULL)
    {
        //daca lista este goala, atunci nodul introdus va fi chiar capul listei
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

int main(void)
{
    node_t *head;
    head=NULL;
    inserare_element_final(&head, "4520", "rigla", "metri", 10);
    inserare_element_final(&head, "4572", "lumanare", "candela", 8);
    inserare_element_final(&head ,"2546", "termometru", "celsius", 54);
    afisare_lista(head);
    return 0;
}





/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structura pentru un produs
struct Produs {
    char cod[5];
    char denumire[16];
    char unitate_masura[3];
    float pret;
    struct Produs* urmatorul;
};

// Funcție pentru afișarea unui produs
void afisare_produs(struct Produs* produs) {
    printf("Cod: %s, Denumire: %s, Unitate de Masura: %s, Pret: %.2f\n", produs->cod, produs->denumire, produs->unitate_masura, produs->pret);
}

// Funcție pentru adăugarea unui produs la sfârșitul listei
void adauga_produs(struct Produs** lista, char cod[], char denumire[], char unitate_masura[], float pret) {
    struct Produs* nou_produs = (struct Produs*)malloc(sizeof(struct Produs));
    if (nou_produs == NULL) {
        fprintf(stderr, "Eroare la alocarea memoriei\n");
        exit(1);
    }

    strncpy(nou_produs->cod, cod, 4);
    strncpy(nou_produs->denumire, denumire, 15);
    strncpy(nou_produs->unitate_masura, unitate_masura, 2);
    nou_produs->pret = pret;
    nou_produs->urmatorul = NULL;

    if (*lista == NULL) {
        *lista = nou_produs;
    } else {
        struct Produs* current = *lista;
        while (current->urmatorul != NULL) {
            current = current->urmatorul;
        }
        current->urmatorul = nou_produs;
    }
}

// Funcție pentru afișarea întregii liste
void afisare_lista(struct Produs* lista) {
    struct Produs* current = lista;
    while (current != NULL) {
        afisare_produs(current);
        current = current->urmatorul;
    }
}

int main() {
    struct Produs* lista = NULL;
    char cod[5];
    char denumire[16];
    char unitate_masura[3];
    float pret;

    int numar_produse;

    printf("Introduceti numarul de produse: ");
    scanf("%d", &numar_produse);

    for (int i = 0; i < numar_produse; i++) {
        printf("Introduceti codul produsului (maxim 4 caractere): ");
        scanf("%s", cod);
        printf("Introduceti denumirea produsului (maxim 15 caractere): ");
        scanf("%s", denumire);
        printf("Introduceti unitatea de masura (maxim 2 caractere): ");
        scanf("%s", unitate_masura);
        printf("Introduceti pretul produsului: ");
        scanf("%f", &pret);

        adauga_produs(&lista, cod, denumire, unitate_masura, pret);
    }

    printf("\nLista de produse:\n");
    afisare_lista(lista);

    // Eliberarea memoriei alocate pentru lista
    while (lista != NULL) {
        struct Produs* temp = lista;
        lista = lista->urmatorul;
        free(temp);
    }

    return 0;
}
*/
