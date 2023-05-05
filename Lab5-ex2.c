//Implementati o functie unsigned* makeRandArray(unsigned seed, unsigned n), care primeste un seed si un numar natural n si 
//returneaza un vector alocat dinamic, continand n numere naturale pseodoaleatoare, uniform distribuite
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned *makeRandArray(unsigned seed, unsigned n) 
{
    int i;
    // alocam memorie pentru vectorul de n elemente
    unsigned* v;
    v = (unsigned*)malloc(n * sizeof(unsigned));
    
    // setam seed-ul pentru generatorul de numere aleatoare
    srand(seed);
    
    // generam n numere pseudorandom, uniform distribuite
    for (i = 0; i < n; i++) 
    {
        v[i] = rand();
    }
    
    return v;
}

int main(void) 
{
    int i;
    unsigned* v;
    v = makeRandArray(234, 10);
    // afisam vectorul de numere pseudorandom
    for (i=0; i<10; i++) 
    {
        printf("%u ", v[i]);
    }
    // eliberam memoria alocata pentru vector
    free(v);
    return 0;
}
