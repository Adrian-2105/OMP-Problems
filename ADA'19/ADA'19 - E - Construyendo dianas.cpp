#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

#define infinite 100000000
#define pb(x) push_back(x)

typedef vector<int> vi;

// Variables globales
int puntos, S, aux;
vi v;

void solve() {
    // Construccion y rellenado de la tabla de PD
    int PD[S+1][puntos+1];

    for (int i = 0; i <= puntos; i++)
        PD[0][i] = infinite;
    for (int i = 1; i <= S; i++)
        PD[i][0] = 0;

    for (int i = 1; i <= S; i++) {
        for (int j = 1; j <= puntos; j++) {
            if (j-v[i-1] >= 0)
                PD[i][j] = min(PD[i-1][j], PD[i][j-v[i-1]] + 1);
            else
                PD[i][j] = PD[i-1][j];
        }
    }

    if (PD[S][puntos] >= infinite)
        cout << "Imposible\n";
    else {
        // Reconstruccion de la solucion
        vector<int> solucion;
        int i = S, j = puntos;
        while (j != 0) {
            if (j - v[i-1] >= 0 && PD[i][j] == PD[i][j-v[i-1]] + 1) {
                j -= v[i-1];
                solucion.pb(v[i-1]);
            }
            else
                i--;
        }
        // Impresion del resultado
        cout << solucion.size() << ":";
        for (auto a : solucion)
            cout << " " << a;
        cout << endl;
    }
}

int main() {
    // Bucle de lectura de datos
    while (cin >> puntos >> S) {
        v.clear();
        for (int i = 0; i < S; i++) {
            cin >> aux;
            v.pb(aux);
        }
        solve();
    }
}
