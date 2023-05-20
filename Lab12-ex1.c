/*Se citeste un cuvant format din maxim 10 litere mici distincte. Afisati in ordine lexicografica toate anagramele cuvantului citit care au proprietatea ca nu contin doua vocale alaturate si nici doua consoane alaturate (practic vocalele si consoanele trebuie sa alterneze).
Daca acest lucru nu este posibil se va afisa mesajul IMPOSIBIL.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 4
#define ST_SZ 100
#define DEBUG 0
#define voc "aeiou"

int st[ST_SZ]={0};


int valid(int *st, int k, char *c)
{
	for(int i; i<k; i++)
	{
		if(st[i]==st[k])
		{
			return 0;
		}
	}
    // c[st[k]] returneaza caracterul de la pozitia respectiva, k
	if((strchr(voc, c[st[k]-1])!=NULL && strchr(voc, c[st[k - 1]-1])==NULL) || (strchr(voc, c[st[k]-1])==NULL && strchr(voc, c[st[k - 1]-1])!=NULL) )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int solutie(int st[], int k, int n)
{
    return (k==n);
}

void tipar(int st[], char *c, int k)
{
    int i;
    for (i=1; i<=k; i++)
	{
        printf("%c ", c[st[i]-1]);
    }
    printf("\n");
}

int cmp_str(const void *a, const void *b)
{
    return(*(char *)a- *(char *)b);
}

int succesor(int st[], int k, int n)
{
	//verifica daca pe nivelul curent mai se poate pune o valoare noua si daca da, o pune si returneaza 1
	//iar daca nu se poate pune returneaza 0;
	if (st[k]<n)
	{
		st[k]++;
		return 1;
	}
	return 0;
}

void back(char *c)
{
	int k=1;
	st[k]=0;
    int n=strlen(c);
    int m=0;
    qsort(c, n, sizeof(char), cmp_str);
	while (k>0)
	{
		
	    if (succesor(st,k, n))
		{
		
	        if (valid(st, k, c))
            {
	            if (solutie(st, k, n))
				{
	                tipar(st, c, k);
	            }
	            else
				{
	               k=k+1;	//trecem pe nivelul urmator;
	               st[k]=0;
	            }
	        }
		}
		else
		{
			k--;	//cobram pe nivelul anterior si continuam de la ultima valoare atinsa
		}
	}
    if(!m)
    {
        printf("Imposibil");
        exit(1);
    }

}

int main()
{
    char c[]="verra";
    back(c);
    return 0;
}
