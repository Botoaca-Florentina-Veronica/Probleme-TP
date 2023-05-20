//ex 1
//Implementati o functie unsigned* makeRandArray(unsigned seed, unsigned n), care primeste un seed si un numar natural n si
//returneaza un vector alocat dinamic, continand n numere naturale pseodoaleatoare, uniform distribuite

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned* makeRandArray(unsigned seed, unsigned n) 
{
    unsigned *arr, i;
    arr = malloc(n * sizeof(unsigned));
    srand(seed);
    for (i = 0; i < n; i++) 
    {
        arr[i] = rand();
    }
    return arr;
}

int main(void) 
{
    unsigned *arr, i;
    arr = makeRandArray(42, 10);
    for (i = 0; i < 10; i++) 
    {
        printf("%u ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}



//ex 2
//Implementati o functie int* makeRandLimitArray(int seed, unsigned n, int a, int b) care primeste un seed, si 
//numerele naturale n, a si b si returneaza un vector alocat dinamic, 
//continand n numere intregi pseudoaleatoare, uniform distribuite, cuprinse intre a si b

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *makeRandLimitArray(int seed, unsigned n, int a, int b)
{
    int i, *v;
    int interval;
    interval = b - a + 1;
    v = (int *)malloc(n * sizeof(int));
    if (v == NULL)
    {
        printf("Eroare alocare dinamica");
        exit(1);
    }
    srand(seed);
    for (i = 0; i < n; i++)
    {
        v[i] = rand() % interval + a;
    }
    return v;
}

int main(void)
{

    int i;
    int *v;
    v = makeRandLimitArray(345, 10, 1, 100);
    for (i = 0; i < 10; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}


//ex 3
/*Implementati o functie cu antetul int* makeRandFlexiArray(unsigned n, int (*getNewElem)(int*, unsigned)) 
care genereaza un vector alocat dinamic cuprinzand elemente numere psoedoaleatoare. Pentru generarea unui nou element 
din vector se va face apel la o functie "concreta" primita sub forma unui pointer la o functie care primeste drept argumente 
un tablou si numarul sau curent de elemente. 
Implementati functii "concrete" pentru generarea unor vectori monoton crescatori si monoton descrescatori.*/
//metoda cu numere unsigned
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* makeRandFlexiArray(unsigned n, int (*getNewElem)(int*, unsigned)) 
{
    int* arr;
    unsigned i;
    arr = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) 
    {
        arr[i] = getNewElem(arr, i);
    }
    return arr;
}

int getNewElemAsc(int* arr, unsigned n) 
{
    if (n == 0) 
    {
        return rand();
    }
    return arr[n-1] + rand();
}

int getNewElemDesc(int* arr, unsigned n) 
{
    if (n == 0) 
    {
        return rand();
    }
    return arr[n-1] - rand();
}

int main(void) 
{
    srand(time(NULL));
    int *arr1;
    unsigned i;
    arr1= makeRandFlexiArray(10, getNewElemAsc);
    printf("Vector crescator:\n");
    for (i = 0; i < 10; i++) 
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    free(arr1);
    int *arr2;
    arr2 = makeRandFlexiArray(10, getNewElemDesc);
    printf("Vector descrescator:\n");
    for (i = 0; i < 10; i++) 
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    free(arr2);
    return 0;
}


//metoda cu numere normale
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
