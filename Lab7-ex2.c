//Implementati o functie care primeste o lista si returneaza un tablou de intregi cu elementele listei.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node
{
    int data;
    struct node *link;
}node_t;


void insert_at_Beggining(int data)
{
    node_t *newnode;
    newnode=(node_t *)malloc(sizeof(node_t));
    newnode->data=data;
    newnode->link=head;
    head=newnode;
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


int count_nodes(node_t *head)
{
    node_t *ptr;
    ptr=head;
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    return count;
}

int *make_array_from_list(node_t *head, int *size)
{
    int i, count=0;
    count = count_nodes(head);

    //alocam dinamic spatiu pentru vector
    int *v;
    v=(int *)malloc(count * sizeof(int));

    //copiem elementele listei în tablou
    node_t *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        v[i++]=ptr->data;
        ptr=ptr->link;
    }
    // setăm valoarea parametrului "size"
    *size=count;
    return v;
}

int main(void)
{
    node_t *head=NULL;
    insert_at_Beggining(4);
    insert_at_Beggining(5);
    insert_at_Beggining(6);
    insert_at_Beggining(7);
    insert_at_Beggining(8);
    print_list(head);

    /*printf("Tabloul de elemente este:\n");
    int i, size;
    int *v=make_array_from_list(head, &size);
    for(i=0; i<size; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    free(v);*/
    return 0;
}
