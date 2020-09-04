/**
\_\\__\\/__///\___\_/\\_\_\__////\////_\\_\/\_/\//__\__/_/_\/\_\\/__\////______\\\\__\_//_/_/\\___///////_\\_\///\__/\//_///_\/\_\/\__/_\_/__/_\\\\_\//\______///__\\///_______\\\\_\/___\////\\\///___\\\_///_/\_\/\//_/\
*/

#include <stdio.h>

int main(void)
{
    int ncasos, cont, mesetas;
    char cadena[11000];
    scanf("%d", &ncasos);

    int i, j;
    for (i=0; i<ncasos; i++)
    {
        scanf("%s", cadena);
        cont = 0;
        mesetas = 0;

        for (j=0; cadena[j] != '\0'; j++)
        {
            if (cont < 3) // Buscamos '/' en esta etapa
            {
                if (cadena[j] == '/')
                    cont++;
                else if (cadena[j] == '\\' || cadena[j] == '_')
                    cont = 0;
            }
            else if (cont == 3) // Buscamos '_' en esta etapa
            {
                if (cadena[j] == '_')
                    cont++;
                else if (cadena[j] == '\\')
                    cont = 0;
            }
            else if (cont == 4) // Buscamos un '\' para iniciar la última etapa
            {
                if (cadena[j] == '\\')
                    cont++;
                else if (cadena[j] == '/')
                    cont = 1;
            }
            else if (cont > 4)
            {
                if (cadena[j] == '\\')
                    cont++;
                else if (cadena[j] == '/')
                    cont = 1;
                else if (cadena[j] == '_')
                    cont = 0;
            }

            if (cont >= 7)
            {
                //printf("%d ", j);
                cont = 0;
                mesetas++;
            }
        }
        printf("%d\n", mesetas);
    }
    return 0;
}
