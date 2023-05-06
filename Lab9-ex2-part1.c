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
