#include <iostream>
#include <stdio.h>

int main()
{
    int i, j, k, ncasos, nentradas, longitud;
    char entrada[100000];
    char x1, x2, x3;
    long long int cont, mayor;

    std::cin >> ncasos;
    for (i=1; i<=ncasos; i++)
    {
        std::cin >> nentradas;
        longitud = 0;
        for(j=0; j<nentradas; j++)
        {
            std::cin >> &entrada[longitud];
            for(; entrada[longitud] != '\0'; longitud++);
        }
        char X1 = 127;
        char X2 = 127;
        char X3 = 127;
        mayor = 0;
        for(j=0; j+2<longitud; j++)
        {

            while(entrada[j] == '#' || entrada[j+1] == '#' || entrada[j+2] == '#')
            {
                if (entrada[j] == '#')
                    j++;
                else if (entrada[j+1] == '#')
                    j+=2;
                else j+= 3;
            }

            cont = 0;
            if (j >= longitud) break;
            x1 = entrada[j];
            x2 = entrada[j+1];
            x3 = entrada[j+2];

            for(k=j+1; k+2<longitud; k++)
            {
                if ((entrada[k] == x1) && (entrada[k+1] == x2) && (entrada[k+2] == x3))
                    cont++;
            }

            if (cont > mayor)
            {
                mayor = cont;
                X1 = x1;
                X2 = x2;
                X3 = x3;
            }
            if (cont == mayor)
            {
                mayor = cont;

                if (x1 < X1)
                {
                    X1 = x1;
                    X2 = x2;
                    X3 = x3;
                }
                else if (x1 == X1)
                {
                    if (x2 < X2)
                    {
                        X1 = x1;
                        X2 = x2;
                        X3 = x3;
                    }
                    else if (x2 == X2)
                        if (x3 < X3)
                        {
                            X1 = x1;
                            X2 = x2;
                            X3 = x3;
                        }
                }

            }
        }
        if (X1 != 127)
            printf("PATENT %c%c%c AND WIN %lli EUROS!\n", X1, X2, X3, (mayor+1)*1000);
        //std::cout << "PATENT " << X1 << X2 << X3 << " AND WIN " << (mayor+1)*1000 << " EUROS!" << std::endl;

    }
    return 0;
}
