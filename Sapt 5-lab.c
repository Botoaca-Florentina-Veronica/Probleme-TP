//2. Implementati o functie int* makeRandLimitArray(int seed, unsigned n, int a, int b) care primeste un seed, si numerele naturale n, a si b si 
//returneaza un vector alocat dinamic, continand n numere intregi pseudoaleatoare, uniform distribuite, cuprinse intre a si b

/* 4.
a) Implementati o functie cu prototipul int findElemLin(int v[], unsigned n, int x) care returneaza pozitia primei aparitii 
a elementului x in vectorul v avand n elemente sau -1 daca acel numar nu apare in vector. Se va folosi un algoritm cu complexitate 
liniara.
b) Implementati o functie cu prototipul int findElemBin(int v[], unsigned n, int x) cauta elementul, similar cu cerinta de la 
punctul a), dar opereaza asupra unui vector sortat. Pentru rezolvare se va folosi un algoritm cu complexitate logartimica 
c) Masurati timpul de executie pentru un numar semnificativ de rulari ale celor doua functii (spre exemplu 100 de rulari) si 
repetati acest proces pentru un set de date din ce in ce mai mare (spre exemplu de la 100 de elemente la 50000 de elemente din 100 de rulări).
Tipariti datele pe iesirea standard si redirectati iesirea spre un fisier .csv, iar mai apoi reprezentati grafic rezultatele 
facand observatii asupra timpilor de executie raportat la marimea datelor de intrare.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// prb 2
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

// prb 4a)
int findElemLin(int v[], unsigned n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            return i;
        }
    }
    return -1;
}

// prb 4b)
void bubble_sort(int *v, unsigned n)
{
    int i, j, temp = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int findElemBin(int v[], unsigned n, int x)
{
    int left, right, mijloc;
    left = 0;
    right = n - 1;
    while (left <= right)
    {
        mijloc = (left + right) / 2;
        if (v[mijloc] == x)
        {
            return mijloc;
        }
        if (x > v[mijloc])
        {
            left = mijloc + 1;
        }
        else if (x < v[mijloc])
        {
            right = mijloc - 1;
        }
    }
    return -1;
}

void timp_de_executie(int n, FILE *f1)
{
    int *v;
    v = makeRandLimitArray(123, n, 3, 1949853);
    clock_t start, end;
    double cpu_time_used1, cpu_time_used2;
    for (int i = 0; i < 100; i++)
    {
        start = clock();
        findElemLin(v, n, v[n - 1]);
        end = clock();
        cpu_time_used1 = ((double)(end - start)) / CLOCKS_PER_SEC;

        start = clock();
        findElemBin(v, n, v[n - 1]);
        end = clock();

        cpu_time_used2 = ((double)(end - start)) / CLOCKS_PER_SEC;
        fprintf(f1, "%f, %f, %d\n", cpu_time_used1, cpu_time_used2, n);
    }
}

int main(void)
{

    int i, d, c;
    int *v;
    // prb 2
    v = makeRandLimitArray(345, 10, 1, 100);
    for (i = 0; i < 10; i++)
    {
        printf("%d ", v[i]);
        d = findElemLin(v, 10, 66);
    }
    printf("\n");

    // prb 4a)
    printf("%d", d);
    printf("\n");

    // prb 4b)
    bubble_sort(v, 10);

    // afisam elementele crescator
    for (i = 0; i < 10; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    c = findElemBin(v, 10, 3);
    printf("%d\n", c);

    FILE *f1;
    f1=fopen("vera.csv", "w");
    fprintf(f1, "Timp_cautare_liniara, Timp_cautare_binara, Nr_elemente");

    timp_de_executie(100, f1);
    timp_de_executie(1000, f1);
    timp_de_executie(10000, f1);
    timp_de_executie(30000, f1);
    timp_de_executie(40000, f1);
    timp_de_executie(50000, f1);
    fclose(f1);
    free(v);
    return 0;
}
