#include <iostream>
#include <stdlib.h>

int valor(char c)
{
    if (c == 'I')
        return 1;
    else if (c == 'V')
        return 5;
    else if (c == 'X')
        return 10;
    else if (c == 'L')
        return 50;
    else if (c == 'C')
        return 100;
    else if (c == 'D')
        return 500;
    else if (c == 'M')
        return 1000;

    return 0;
}

void RtoD(char *s)
{
    int top = 0;
    int cont = 0;
    int ac = 0;
    int i = 0;
    while (s[i] != '\0')
        i++;

    for (; i>=0; i--)
    {
        ac = valor(s[i]);
        if (ac >= top)
        {
            top = ac;
            cont += ac;
        }
        else
            cont -= ac;
    }
    std::cout << cont << std::endl;
}

void DtoR(char *s)
{
    int n = atoi(s);

    while (n >= 1000) { std::cout << "M"; n -= 1000; }
    if (n >= 900) { std::cout << "CM"; n -= 900; }
    if (n >= 500) { std::cout << "D"; n -= 500; }
    if (n >= 400) { std::cout << "CD"; n -= 400; }
    while (n >= 100) { std::cout << "C"; n -= 100; }
    if (n >= 90) { std::cout << "XC"; n -= 90; }
    if (n >= 50) { std::cout << "L"; n -= 50; }
    if (n >= 40) { std::cout << "XL"; n -= 40; }
    while (n >= 10) { std::cout << "X"; n -= 10; }
    if (n >= 9) { std::cout << "IX"; n -= 9; }
    if (n >= 5) { std::cout << "V"; n -= 5; }
    if (n >= 4) { std::cout << "IV"; n -= 4; }
    while (n >= 1) { std::cout << "I"; n -= 1; }
    std::cout << std::endl;
}


int main()
{
    int n;
    char cadena[1000];
    while (std::cin >> cadena)
    {
        if (!(cadena[0] > '9')) // Decimal a romano
            DtoR(cadena);
        else                                    // Romano a decimal
            RtoD(cadena);
    }
    return 0;
}
