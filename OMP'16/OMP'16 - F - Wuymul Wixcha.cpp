#include <stdio.h>
#include <stdlib.h>

#define diferencia 'Z'-'A'+1
#define difAa 'a'-'A'

int main(void)
{
    int sum;
    int i;
    size_t A = 10001;
    char cadena[A];
    char filtro[5];
    scanf("%d", &sum);

    while (sum != 0)
    {
        scanf("%[\n]", filtro);
        sum %= diferencia;
        scanf("%[^\n]", cadena);
        //fgets(cadena, 10000, stdin);
        //getline(cadena, &A, stdin);
        for (i=0; cadena[i] != '\0'; i++)
        {
            if (cadena[i] >= 'A' && cadena[i] <= 'Z')
            {
                cadena[i] += sum;
                if (!(cadena[i] >= 'A' && cadena[i] <= 'Z'))
                {
                    if (cadena[i] < 'A')
                        cadena[i] += diferencia;
                    if (cadena[i] > 'Z')
                        cadena[i] -= diferencia;
                }
            }
            else if (cadena[i] >= 'a' && cadena[i] <= 'z')
            {
                cadena[i] -= difAa; // necesario hacer por el desbordamiento
                cadena[i] += sum;
                if (!(cadena[i] >= 'A' && cadena[i] <= 'Z'))
                {
                    if (cadena[i] < 'A')
                        cadena[i] += diferencia;
                    if (cadena[i] > 'Z')
                        cadena[i] -= diferencia;
                }
                cadena[i] += difAa;
            }
        }
        printf("%s\n", cadena);
        scanf("%d", &sum);
    }
    return 0;
}
