#include <stdio.h>
#include <math.h>

int palindromo(int n)
{
    char s[20];
    sprintf(s, "%d", n);
    int caracteres = 0;
    while (s[caracteres] != '\0')
        caracteres++;
    int i;
    for (i=0; i<caracteres/2; i++)
        if (s[i] != s[caracteres-i-1])
            return 0;
    return 1;
}


int primo(int n)
{

    if (n<2)
        return 0;
    int i;
    for(i=2; i<=sqrt(n); i++)
        if(n%i == 0) return 0;
    return 1;
}


int main(void)
{
    int n;
    do
    {
        scanf("%d", &n);
        printf("%d\n", n*2);
    }
    while (!(palindromo(n) && primo(n)));
    return 0;
}
