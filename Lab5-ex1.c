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
