#include <stdio.h>
#include <math.h>

typedef struct {
    int xini,yini;
    int xfin, yfin;
} pos;

int main(void)
{
    int num_casos;
    scanf("%d", &num_casos);
    int i;
    for (i=0; i<num_casos; i++)
    {
        scanf("\n");
        int num_casos_tablero, tamano;
        scanf("%d", &num_casos_tablero);
        scanf("%d", &tamano);
        int j;
        for (j=0; j<num_casos_tablero; j++)
        {
            pos bishop;
            scanf("%d %d %d %d", &bishop.xini, &bishop.yini, &bishop.xfin, &bishop.yfin);
            if (((bishop.xini + bishop.yini)%2 != (bishop.xfin + bishop.yfin)%2)) // si no tienen el mismo color de casilla
            {
                printf("no move\n");
            } else if ((bishop.xini == bishop.xfin) && (bishop.yini == bishop.yfin))
            {
                printf("0\n");
            } else if (abs(bishop.xfin-bishop.xini) == abs(bishop.yfin-bishop.yini))
            {
                printf("1\n");
            } else
                printf("2\n");
        }
    }
    return 0;
}
