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
}
