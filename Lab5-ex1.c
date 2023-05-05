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
