//circular single linked list-insertion at the beggining of a list
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

node_t *addToBeggining(node_t *tail, int data)
{
	node_t *ptr;
	ptr = (node_t *)malloc(sizeof(node_t));
	ptr->data = data;
	ptr->link = tail->link;
	tail->link = ptr;

	return tail;
}

void print_list(node_t *tail)
{
	node_t *ptr;
	ptr = tail->link;
	//facem do-while fiindca daca incep direct cu while, bucla mea se va termina inainte sa inceapa sa parcurga lista
	//fiindca deja am initializat pointer ul ptr cu valoarea limita a conditiei
	do
	{
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}while(ptr!=tail->link);
	printf("\n");
}

int main(void)
{
	//ca in ficare implementare de lista, atunci cand introducem la inceput un element, acesta va fi pus pe o stiva
	//dupa ce ne introducem toate elementele in lista si o vom citi, vom incepe citirea cu ultimul element introdus
	//de exemplu, atunci cand introducem rondele de ananas intr-un borcan de sticla. Pentru a ajunge la prima bucata
	//trebuie sa le scoatem pe toate celelalte aflate deasupra ei.
	node_t * tail;
	tail = addToEmptyList(34);
	tail = addToBeggining(tail, 45);
	tail = addToBeggining(tail, 56);
	tail = addToBeggining(tail, 67);
	print_list(tail);
	//se va afisa 67, 56, 45, 34
	return 0;
}
