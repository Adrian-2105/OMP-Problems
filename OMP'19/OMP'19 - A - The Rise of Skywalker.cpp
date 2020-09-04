#include <iostream>

int ordenar(int * entrada, int n)

{
    int i, j, aux;
    int suma = 0;
    for(i=0; i<n; i++)
    {
        for(j=i; j<n; j++)
        {
            if (entrada[j] > entrada[i])
            {
                aux = entrada[i];
                entrada[i] = entrada[j];
                entrada[j] = aux;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        suma+=entrada[i];
    }
    return suma;
}

int main()
{
    int N;
    int i;
    int j;
    int ncasos;
    int G[140];
    int planetas;
    int mayor;
    int suma, meta;
    std::cin >> ncasos;
    for (i=1; i<=ncasos; i++)
    {
        std::cin >> N;
        j = 0;
        while(j < N)
        {
            std::cin >> G[j];
            j++;
        }
        meta = ordenar(G, N);
        suma = 0;
        for(planetas=0; suma<=(meta/2); planetas++)
        {
            suma+=G[planetas];
        }
        std::cout << "Case " << i << ": " << planetas << " planets" << std::endl;
    }
    return 0;
}
