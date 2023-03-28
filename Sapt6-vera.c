//prb 1
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
} Node;

typedef struct
{
    Node* top;
    int size;
} Stack;


Stack* createStack()
{
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

int isEmpty(Stack* stack)
{
    return (stack->top == NULL);
}

void push(Stack* stack, int data)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

int pop(Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

int peek(Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->top->data;
}

int size(Stack* stack)
{
    return stack->size;
}

void destroyStack(Stack* stack)
{
    Node* current = stack->top;
    while (current != NULL)
    {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}
int main() 
{
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top element is %d\n", peek(stack));
    printf("Stack size is %d\n", size(stack));

    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));

    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }

    destroyStack(stack);
    return 0;
}


//prb 3
#include <stdio.h>
#include <stdlib.h>

// Definim o structură pentru nodurile listei
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Funcție pentru adăugarea unui element la sfârșitul listei
void add(Node** head, int data) {
    // Creăm un nou nod
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // Dacă lista e goală, facem noul nod capul listei
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Parcurgem lista până la ultimul nod
    Node* last = *head;
    while (last->next != NULL)
        last = last->next;

    // Adăugăm noul nod la sfârșitul listei
    last->next = newNode;
}

// Funcție pentru eliminarea duplicatelor consecutive
void removeDuplicates(Node* head) {
    Node* current = head;

    // Parcurgem lista
    while (current != NULL) {
        // Verificăm dacă următorul nod are aceeași valoare
        if (current->next != NULL && current->data == current->next->data) {
            // Salvăm referința către nodul duplicat
            Node* duplicate = current->next;
            // Legăm nodul curent de nodul de după nodul duplicat
            current->next = current->next->next;
            // Eliberăm memoria alocată pentru nodul duplicat
            free(duplicate);
        } else {
            // Trecem la următorul nod
            current = current->next;
        }
    }
}

// Funcție pentru afișarea listei
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Exemplu de utilizare

    // Cream lista: 1 -> 2 -> 2 -> 3 -> 3 -> 3 -> 4 -> 5 -> 5
    Node* head = NULL;
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
    Node* current = head;
    while (head != NULL) {
        head = head->next;
        free(current);
        current = head;
    }

    return 0;
}
