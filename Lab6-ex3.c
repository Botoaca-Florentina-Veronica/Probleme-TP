//Implementați o funcție care primește o listă de numere întregi și elimină orice duplicate consecutive (lăsând doar o singură valoare din orice secvență de valori egale). 
//Modificați lista în loc și eliberați memoria pentru valorile șterse.
#include <stdio.h>
#include <stdlib.h>

// Definim o structură pentru nodurile listei
typedef struct node 
{
    int data;
    struct node *link;
}node_t;

// Funcție pentru adăugarea unui element la sfârșitul listei
void add(node_t** head, int data) 
{
    // Creăm un nou nod
    node_t *newNode = (node_t *) malloc(sizeof(node_t));
    newNode->data = data;
    newNode->link = NULL;

    // Dacă lista e goală, facem noul nod capul listei
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }

    // Parcurgem lista până la ultimul nod
    node_t *last = *head;
    while (last->link != NULL)
        last = last->link;

    // Adăugăm noul nod la sfârșitul listei
    last->link = newNode;
}

// Funcție pentru eliminarea duplicatelor consecutive
void removeDuplicates(node_t *head) 
{
    node_t *ptr;
    ptr = head;

    // Parcurgem lista
    while (ptr != NULL) 
    {
        // Verificăm dacă următorul nod are aceeași valoare
        if (ptr->link != NULL && ptr->data == ptr->link->data) 
        {
            // Salvăm referința către nodul duplicat
            node_t *duplicate;
            duplicate= ptr->link;
            // Legăm nodul curent de nodul de după nodul duplicat
            ptr->link = ptr->link->link;
            // Eliberăm memoria alocată pentru nodul duplicat
            free(duplicate);
        } 
        else 
        {
            // Trecem la următorul nod
            ptr = ptr->link;
        }
    }
}

// Funcție pentru afișarea listei
void printList(node_t *head) 
{
    node_t *ptr;
    ptr = head;
    while (ptr != NULL) 
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

int main(void) 
{
    // Exemplu de utilizare

    // Cream lista: 1 -> 2 -> 2 -> 3 -> 3 -> 3 -> 4 -> 5 -> 5
    node_t *head = NULL;
    add(&head, 1);
    add(&head, 2);
    add(&head, 2);
    add(&head, 3);
    add(&head, 3);
    add(&head, 3);
    add(&head, 4);
    add(&head, 5);
    add(&head, 5);

    printf("Lista initiala: ");
    printList(head);

    // Eliminam duplicatatele
    removeDuplicates(head);

    printf("Lista fara duplicate consecutive: ");
    printList(head);

    // Eliberam memoria
    node_t *ptr;
    ptr = head;
    while (head != NULL) 
    {
        head = head->link;
        free(ptr);
        ptr = head;
    }

    return 0;
}
