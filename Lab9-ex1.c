//ex 1
/*
  Rădăcina unei funcţii. Găsiţi, cu o aproximaţie dată (de exemplu 10-6), o rădăcină a unei funcţii f continuă pe un interval [a, b]
şi care schimbă semnul pe acel interval (adică o valoare x pentru care f(x) = 0).
  Rezolvaţi problema pentru o funcţie dată (de exemplu f(x) = x2 - 3) pe care o definiţi în program, şi alegeţi valori 
  corespunzătoare pentru a şi b (de exemplu 1 şi 3).
Indicaţii Deoarece f(a) ≤ 0 (f(1) = 1 * 1 - 3 = -2) şi f(b) ≥ 0 (f(3) = 3*3 - 3 = 6) iar funcţia e continuă pe [a, b], 
ea va avea o rădăcină în acest interval. Problema se rezolvă înjumătăţind la fiecare pas intervalul de căutare pe care funcţia 
schimbă semnul, până când acesta devine mai mic decât precizia dată. Atunci orice punct din interval e o soluţie cu precizia 
cerută.
Se calculează valoarea funcţiei în mijlocul intervalului. Dacă valoarea funcţiei e ≥ 0, funcţia schimbă semnul pe jumătatea 
din stânga a intervalului. Altfel (dacă valoarea funcţiei la mijlocul intervalului e < 0), funcţia schimbă semnul pe jumătatea 
din dreapta. (în exemplul dat, f(2) = 2*2 - 3, şi cum f(2) ≥ 0, continuăm cu intervalul [1,2]). Ajungem astfel la aceeaşi problemă, 
dar cu intervalul redus la jumătate. Continuând să înjumătăţim lungimea intervalului ajungem la cazul de bază, când putem returna 
orice valoare din interval (de exemplu mijlocul).
Se poate eventual testa suplimentar dacă în mijlocul intervalului, funcţia are valoarea zero, şi returna direct rădăcina în acest 
caz.
*/
// sa pui la final -lm pentru biblioteca math.h daca crapa codul
//adica asa: gcc -Wall -o vera vera.c -lm
#include <stdio.h>
#include <math.h>

double f(double x) 
{
    return x*x - 3;  // definim functia f(x) = x^2 - 3
}

double bisection(double a, double b, double epsilon) 
{
    double c;
    while (b - a > epsilon) 
    {  
        // cat timp intervalul mai este mai mare decat precizia
        c = (a + b) / 2;  // calculam mijlocul intervalului
        if (f(c) == 0) 
        {
            return c;  // daca gasim rădăcina exacta, o returnam
        } 
        else if (f(a)*f(c) < 0) 
        {
            b = c;  // daca f(a) si f(c) au semne opuse, radacina e in intervalul [a, c]
        } 
        else 
        {
            a = c;  // altfel, radacina e in intervalul [c, b]
        }
    }
    return (a + b) / 2;  // returnam mijlocul intervalului final ca aproximare a rădăcinii
}

int main(void) 
{
    double a = 1, b = 3, epsilon = 1e-6;
    double root = bisection(a, b, epsilon);
    printf("O rădăcină a funcției x^2 - 3 în intervalul [%g, %g] cu precizia %g este: %g\n", a, b, epsilon, root);
    return 0;
}





//ex 2
/*Numere în format hexazecimal. Scrieţi o funcţie care returnează valoarea unui număr citit de la intrare caracter cu 
caracter, în format hexazecimal (cifrele 0-9, A-F sau a-f).
Indicaţii: problema e similară cu funcţia readnat de la curs. Un prim test se face pentru cifra hexazecimala 
(isxdigit, tot din ctype.h), apoi pentru a obţine valoarea cifrei trebuie tratat diferit cazul cifrelor şi al literelor
(de la A la F). Cum scrierea cu litere mari sau mici nu contează se poate folosi funcţia toupper din ctype.h 
(returnează literă mare dacă argumentul e literă mică; altfel returnează chiar litera dată ca argument) 
pentru a trata cele două cazuri uniform. (La fel de bine se poate folosi funcţia pereche tolower).*/
#include <stdio.h>
#include <ctype.h>

int hex_to_decimal(char c) 
{
    if(isdigit(c))
    {
        return c-'0';
    }
    else
    {
        if(c>='a' && c<'z')
        {
            return c-'a'+10;
        }
        else
        {
            return c-'A'+10;
        }
    }
}

int hexa()
{
    int number = 0;
    char c;

    while ((c = getc(stdin)) != EOF)
    {
        if (isxdigit(c))
        {
            number = number * 16 + hex_to_decimal(c);
        }
        else
        {
            break;
        }
    }

    return number;
}

int main(void) 
{
    int number = hexa();
    printf("%d\n", number);
    return 0;
}
