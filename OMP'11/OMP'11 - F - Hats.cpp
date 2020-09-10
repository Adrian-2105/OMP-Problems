/*
 * Esta estrategia de resolución es muy sucia, pero es igual de válida.
 * Obtenemos todas las soluciones posibles mediante backtracking y posteriormente
 * incluimos todas las posibles soluciones en un análisis de casos.
 *
 * Lo haría de la forma simple, pero desgraciadamente mi nivel de combinatoria
 * no me da para tanto xD
 */


#include <iostream>
#include <string.h>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair

// #define CALCULAR_SOLUCIONES

pii soluciones[13];
#define posibles first
#define totales second

int sombreros[13];

bool caseOK(int n) {
    for (int i = 1; i <= n; i++)
        if (sombreros[i] == i)
            return false;
    return true;
}

bool disponible(int n, int sombrero) {
    for (int i = 1; i <= n; i++)
        if (sombreros[i] == sombrero)
            return false;
    return true;
}

void backtracking(int n, int persona) {
    // Checkear solucion
    if (persona > n) {
        if (caseOK(n))
            soluciones[n].posibles++;
        soluciones[n].totales++;
        return;
    }
    for (int sombrero = 1; sombrero <= n; sombrero++) {
        if (disponible(n, sombrero)) {
            sombreros[persona] = sombrero;
            backtracking(n, persona + 1);
        }
    }
    sombreros[persona] = 0;
}

int main() {
#ifdef CALCULAR_SOLUCIONES
    // Cálculo de las 11 soluciones existentes
    memset(sombreros, 0, sizeof(sombreros));
    for (int i = 2; i <= 12; i++) {
        soluciones[i] = mp(0,0);
        backtracking(i, 1);
        cout << soluciones[i].posibles << "/" << soluciones[i].totales << endl;
    }
#else
    // Bucle principal
    int casos, n;
    cin >> casos;
    while (casos--) {
        cin >> n;
        switch (n) {
            case 2:
                cout << "1/2\n";
                break;
            case 3:
                cout << "2/6\n";
                break;
            case 4:
                cout << "9/24\n";
                break;
            case 5:
                cout << "44/120\n";
                break;
            case 6:
                cout << "265/720\n";
                break;
            case 7:
                cout << "1854/5040\n";
                break;
            case 8:
                cout << "14833/40320\n";
                break;
            case 9:
                cout << "133496/362880\n";
                break;
            case 10:
                cout << "1334961/3628800\n";
                break;
            case 11:
                cout << "14684570/39916800\n";
                break;
            case 12:
                cout << "176214841/479001600\n";
                break;
        }
    }
#endif
}
