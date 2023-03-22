//In C implementati o functie unsigned* makeRandArray(unsigned seed, unsigned n), care
//primeste un seed si un numar natural n si returneaza un vector alocat dinamic,
//continand n numere naturale pseodoaleatoare, uniform distribuite

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//prb 1
unsigned* makeRandArray(unsigned seed, unsigned n)
{
    int i;
    unsigned *arr = malloc(n * sizeof(unsigned));  // alocam dinamic vectorul
    srand(seed);  // setam seed-ul
    for (i=0; i<n; i++)
    {
        arr[i] = rand();  // generam numere pseudo-aleatoare
    }
    return arr;
}

//prb 2
int* makeRandLimitArray(int seed, unsigned n, int a, int b)
{
    int i, num=0;
    int *arr2 = malloc(n * sizeof(int));  // alocam dinamic vectorul
    srand(seed);  // setam seed-ul

    int range = b - a + 1;  // determinam intervalul de numere posibile
    for (i=0; i<n; i++)
    {
        num = rand() % range + a;  // generam numere pseudo-aleatoare
        arr2[i] = num;
    }

    return arr2;
}

int main(void)
{
    int i;
    //prb 1
    unsigned *arr = makeRandArray(123, 10);  // apelam functia si stocam rezultatul intr-un vector
    for (i=0; i<10; i++)
    {
        printf("%u ", arr[i]);
    }
    printf("\n");

    //prb 2
    int *arr2 = makeRandLimitArray(123, 10, 1, 10);  // apelam functia si stocam rezultatul intr-un vector
    for (i=0; i <10; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    free(arr);
    free(arr2);
    return 0;
}


// prb 3.Implementati o functie cu antetul int* makeRandFlexiArray(unsigned n, int (*getNewElem)(int*, unsigned)) 
//care genereaza un vector alocat dinamic cuprinzand elemente numere psoedoaleatoare. Pentru generarea unui 
//nou element din vector se va face apel la o functie "concreta" primita sub forma unui pointer la o functie care 
//primeste drept argumente un tablou si numarul sau curent de elemente. Implementati functii "concrete" pentru generarea 
//unor vector monon crescatori si moniton descrescatori.

#include<stdio.h>
#include<stdlib.h>

int* makeRandFlexiArray(unsigned n, int (*getNewElem)(int*, unsigned));

int ascending(int *arr, unsigned n) 
    {
        // Generăm un element mai mare cu cel puțin 1 decât ultimul element din vector
        return arr[n-1] + rand() % 10 + 1; 
    }

int descending(int *arr, unsigned n)
    // Generăm un element mai mic cu cel puțin 1 decât ultimul element din vector
    {
        return arr[n-1]-rand() % 10 - 1;
    }

int* makeRandFlexiArray(unsigned n, int (*getNewElem)(int*, unsigned)) 
{
    unsigned i;
    int *arr = malloc(n * sizeof(int)); // Alocăm vectorul dinamic
    if (arr==NULL) 
    { // Verificăm dacă alocarea a eșuat
        printf("Alocarea memoriei a eșuat\n");
        return NULL;
    }
    arr[0] = rand() % 100; // Generăm primul element al vectorului
    for (i=1; i<n; i++) 
    {
        arr[i] = getNewElem(arr, i); // Generăm restul elementelor vectorului utilizând funcția concretă
    }
    return arr; // Returnăm vectorul generat
}

int main(void) 
{
    unsigned i, n = 10;
    int *arr;

    printf("Vector crescator:\n");
    arr = makeRandFlexiArray(n, ascending);
    for (i=0; i<n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);

    printf("Vector descrescator:\n");
    arr = makeRandFlexiArray(n, descending);
    for (i=0; i<n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}





