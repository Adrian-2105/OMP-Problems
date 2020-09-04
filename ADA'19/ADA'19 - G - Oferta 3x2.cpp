#include <iostream>
#include <stdlib.h>
// Devuelve la posición del array en la que se encuentra el mayor número
int mayor(int* arr, int T)
{
    int mayor = 0;
    int pos = 0;
    int i;
    for (i=0; i<T; i++)
        if (arr[i] > mayor)
        {
            mayor = arr[i];
            pos = i;
        }
    return pos;
}

int menor_valor(int* arr, int T)
{
    int menor = 20000;
    int i;
    for (i=0; i<T; i++)
        if (arr[i] <= menor)
            menor = arr[i];
    return menor;
}

int main()
{
    int nlibros, n, i, j, descuento, aux;
    while (std::cin >> nlibros)
    {

        int arr[nlibros];
        n = nlibros;                    // nlibros =  número introducido; n = contador de libros restantes
        descuento = 0;
        for (i=0; i<nlibros; i++)
            std::cin >> arr[i];         // Leemos todos los precios y los guardamos en el array "arr"

        while (n >= 3)
        {
            int pack[3];
            for (i=0; i<3; i++)
                pack[i] = 0;            // Creamos e inicializamos a 0 un pack de libros

            for (j=0; j<3; j++)         // Rellenamos el pack con los 3 libros más caros
            {
                aux = mayor(arr, nlibros);
                pack[j] = arr[aux];
                arr[aux] = 0;
            }

            descuento += menor_valor(pack, 3); // Cogemos el libro más barato y aplicamos el descuento
            n -= 3;
        }
        std::cout << descuento << std::endl;
    }

    return 0;
}
