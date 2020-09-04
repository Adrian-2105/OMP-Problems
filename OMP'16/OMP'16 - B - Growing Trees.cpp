#include <iostream>

int main()
{
    int lvl, i;
    long long int hojas, ant, aux;
    std::cin >> lvl;
    while (lvl != 0)
    {
        ant = 1;
        hojas = 1;
        for (i=1; i<lvl-1; i++)
        {
            aux = hojas + ant;
            ant = hojas;
            hojas = aux;

        }
        std::cout << hojas << std::endl;
        std::cin >> lvl;
    }

    return 0;
}
