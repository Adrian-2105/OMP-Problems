#include <stdio.h>

#define M 0
#define A 1
#define R 2
#define G 3
#define I 4
#define T 5

int main(void)
{
    int ncasos, sol;
    scanf("%d", &ncasos);

    char cadena[601];
    int pizza[6]; // M A R G I T

    int i, j;
    for(i=0; i<ncasos; i++)
    {
        scanf("%s", cadena);

        for(j=M; j<=T; j++)
            pizza[j] = 0;

        for(j=0; cadena[j] != '\0'; j++)
        {
            switch (cadena[j])
            {
            case 'M':
                pizza[M]++;
                break;
            case 'A':
                pizza[A]++;
                break;
            case 'R':
                pizza[R]++;
                break;
            case 'G':
                pizza[G]++;
                break;
            case 'I':
                pizza[I]++;
                break;
            case 'T':
                pizza[T]++;
                break;
            }
        }

        pizza[A] /= 3;
        pizza[R] /= 2;

        sol = pizza[M];
        for(j=A; j<=T; j++)
        {
            if (pizza[j] < sol)
                sol = pizza[j];
        }
        printf("%d\n", sol);
    }

    return 0;
}
