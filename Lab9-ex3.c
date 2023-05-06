/*
    Serii de puteri. 
Calculaţi, cu o precizie dată, valoarea lui ex după dezvoltarea în serie Taylor:
ex = 1 + x1/1! + x2/2! + x3/3! + ...
Calculaţi suma până când termenul curent devine mai mic decât o valoare dată (de ex. 10-6). 
Pentru a evita recalcularea lui n! transmiteţi ca parametru şi 
termenul curent, şi calculaţi-l pe următorul după relaţia: xn/n! = xn-1/(n-1)! * x/n.*/


/*Pentru a calcula valoarea lui ex după dezvoltarea în serie Taylor, putem folosi următorul algoritm:

Inițializăm suma s cu 1 și termenul curent x cu 1.
Inițializăm un contor n cu 1.
Într-un buclă while, calculăm următorul termen xn/n! folosind formula xn/n! = xn-1/(n-1)! * x/n și verificăm dacă acesta este mai mic decât precizia dată.
Dacă xn/n! este mai mic decât precizia dată, ieșim din buclă și returnăm valoarea curentă a sumei.
Altfel, adăugăm xn/n! la suma s și creștem contorul n cu 1.
Actualizăm termenul curent x cu xn/n! și reluăm bucla while.
Codul pentru implementarea acestui algoritm este următorul:*/

#include <stdio.h>

double calc_exp(double x, double precision) 
{
    double sum = 1.0;
    double term = 1.0;
    int n = 1;
    while (term > precision) 
    {
        term = term * x / n;
        sum += term;
        n++;
    }
    return sum;
}

int main(void) 
{
    double x = 1.0;
    double precision = 1e-6;
    double result = calc_exp(x, precision);
    printf("e^%f = %f\n", x, result);
    return 0;
}
