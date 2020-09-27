#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define REP(i, j) FOR(i, 0, j, 1)
#define pb(x) push_back(x)

int nodos, aristas;

bool M[26][26];
bool despierto[26];

int contar() {
    int cont = 0;
    REP(i, 26)
        if (despierto[i])
            cont++;
    return cont;
}

void nuevos() {
    // Vemos cuales despiertan
    vi adds;
    REP(i, 26) {
        if (!despierto[i]) {
            int cont = 0;
            REP(j, 26) {
                if (M[i][j] && despierto[j])
                    cont++;
            }
            if (cont >= 3)
                adds.pb(i);
        }
    }

    // Despertamos a los nuevos
    for (int i : adds)
        despierto[i] = true;
}

void solve() {
    // Lectura entrada
    string aux;
    cin >> aristas;
    cin >> aux;
    REP(i, 3)
        despierto[aux[i] - 'A'] = true;
    REP(i, aristas) {
        cin >> aux;
        M[aux[0] - 'A'][aux[1] - 'A'] = true;
        M[aux[1] - 'A'][aux[0] - 'A'] = true;
    }

    int ant = 3, i;
    // Resolución
    for (i = 1; ant != nodos; i++) {
        nuevos();
        int A = contar();
        if (A == ant) {
            i = -1;
            break;
        }
        ant = A;
    }

    if (i == -1)
        cout << "THIS BRAIN NEVER WAKES UP\n";
    else
        cout << "WAKE UP IN, " << --i << ", YEARS\n";

}

int main() {
    while (cin >> nodos) {
        memset(M, false, sizeof(M));
        memset(despierto, false, sizeof(despierto));
        solve();
    }
}

