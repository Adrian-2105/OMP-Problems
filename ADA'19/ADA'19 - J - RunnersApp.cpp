#include <iostream>

int main()
{
    int inicio;
    int n, tiempo, i, j, aux, cont;
    std::cin  >> n;
    while (n != 0)
    {
        // Leemos el array
        int tramos[n];
        for(i=0; i<n; i++)
            std::cin >> tramos[i];

        // Caso base
        inicio = 0;
        tiempo = 0;
        for (i=0; i<10; i++)
            tiempo += tramos[i];

        // Caso recursivo
        for(i=1; i+10<=n; i++)
        {
            aux = 0;
            for(j=i; j<i+10; j++)
                aux += tramos[j];
            if (aux <= tiempo)
            {
                tiempo = aux;
                inicio = i;
            }
        }
        // Imprimimos la solución
        std::cout << inicio*100 << "-" << (inicio+10)*100 << " " << tiempo/60 << ":" << tiempo%60 << std::endl;
        std::cin  >> n;
    }
    return 0;
}
