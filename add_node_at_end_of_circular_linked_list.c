//circular single linked list-insertion at the end of a list
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
	struct node *prev;
}node_t;

//functie pentru a adauga noduri in lista circulara:
node_t *addToEmptyList(int data)
{
	node_t *temp;
	temp = (node_t *)malloc(sizeof(node_t));
	temp->data = data;
	temp->link = temp;

	return temp;
}

node_t *addToEnd(node_t *tail, int data)
{
	node_t *ptr;
	ptr = (node_t *)malloc(sizeof(node_t));
	ptr->data = data;
	ptr->link = NULL;

	ptr->link = tail->link;
	tail->link = ptr;
	tail = tail->link;

	return tail;
}

void print_list(node_t *tail)
{
	node_t *ptr;
	ptr = tail->link;
	do
	{
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}while(ptr!=tail->link);
	printf("\n");
}

int main(void)
{
	node_t * tail;
	tail = addToEmptyList(34);
	tail = addToEnd(tail, 45);
	tail = addToEnd(tail, 56);
	tail = addToEnd(tail, 67);
	print_list(tail);
	//se va afisa 34 45 56 67
	return 0;
}
