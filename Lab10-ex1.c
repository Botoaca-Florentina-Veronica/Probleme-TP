//1. Implementati algorimtul de cautare binara pe o lista simplu inlantuita 
//(se va implementa sub forma de ArrayList pentru a permite acces aleator la elemente).
#include <stdio.h>
#include <stdlib.h>

// structura nodului din lista
typedef struct node 
{
    int data;
    struct node *link;
} node_t;

// structura pentru lista
typedef struct ArrayList 
{
    int size;
    node_t *head;
} ArrayList;

// functie pentru a adauga un element in lista
void add(ArrayList *list, int data) 
{
    node_t *temp, *ptr;
    temp = (node_t *)malloc(sizeof(node_t));
    if(temp==NULL)
    {
        printf("Nu s-a putut aloca memorie dinamica!!");
        exit(1);
    }
    temp->data = data;
    temp->link = NULL;
    if (list->head == NULL) 
    {
        list->head = temp;
    } 
    else 
    {
        ptr = list->head;
        while (ptr->link != NULL) 
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
    list->size++;
}

// functie pentru a afisa lista
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

// functie pentru a cauta un element in lista
int binarySearch(ArrayList* list, int data) 
{
    int left = 0, i;
    int right = list->size - 1;
    while (left <= right) 
    {
        int mid = (left + right) / 2;
        node_t *ptr;
        ptr = list->head;
        for (i = 0; i < mid; i++) 
        {
            ptr = ptr->link;
        }
        if (ptr->data == data) 
        {
            return mid;
        } 
        else if (ptr->data < data) 
        {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main(void) 
{
    ArrayList list = {0, NULL};
    add(&list, 1);
    add(&list, 2);
    add(&list, 3);
    add(&list, 4);
    add(&list, 5);
    add(&list, 6);
    add(&list, 7);
    add(&list, 8);
    add(&list, 9);
    add(&list, 10);
    printf("List: ");
    printList(list.head);
    int index = binarySearch(&list, 6);
    if (index == -1) 
    {
        printf("Elementul cautat nu a fost gasit.\n");
    } 
    else 
    {
        printf("Elementul cautat a fost gasit la pozitia %d.\n", index);
    }
    return 0;
}
