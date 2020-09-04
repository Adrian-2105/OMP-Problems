#include <stdio.h>

int main(void)
{
    int dia1mes[12] = {5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3};
    int numcasos, M, D, aux;
    scanf("%d", &numcasos);

    int i;
    for (i=0; i<numcasos; i++)
    {
        scanf(" %d %d", &M, &D);
        aux = dia1mes[M-1];
        aux = (D+aux-1)%7;
        //printf("%d\n", aux);
        switch (aux)
        {
        case 0:
            printf("Monday\n");
            break;
        case 1:
            printf("Tuesday\n");
            break;
        case 2:
            printf("Wednesday\n");
            break;
        case 3:
            printf("Thursday\n");
            break;
        case 4:
            printf("Friday\n");
            break;
        case 5:
            printf("Saturday\n");
            break;
        case 6:
            printf("Sunday\n");
            break;
        }
    }
    return 0;
}
