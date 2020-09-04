#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

typedef pair<int, int> pii;

#define nodo first
#define peso second


int M[1050][1050], I, P, a, b, c;
bool vis[1050];
vector<pii> v;

void insertaOrd(pii p) {
    for (int i = 0; i < v.size(); i++) {
        if (p.peso < v[i].peso) {
            v.insert(v.begin() + i, p);
            return;
        }
    }
    v.insert(v.end(), p);
}


int prim() {
    v.clear();
    vis[0] = true;

    for (int i = 1; i < I; i++) {
        if (M[0][i] != 0)
            insertaOrd({i, M[0][i]});
    }

    int suma = 0;
    int visitados = 1;

    while (!v.empty()) {
        pii h = v[0];
        v.erase(v.begin());

        if (vis[h.nodo])
            continue;

        vis[h.nodo] = true;
        suma += h.peso;
        visitados++;

        for (int i = 0; i < I; i++) {
            if (!vis[i] && M[h.nodo][i] != 0)
                insertaOrd({i, M[h.nodo][i]});
        }
    }

    if (visitados == I)
        return suma;
    else
        return -1;
}

int main() {

    while (cin >> I >> P) {
        memset(M, 0, sizeof(M));
        memset(vis, false, sizeof(vis));

        for (int i = 0; i < P; i++) {
            cin >> a >> b >> c;
            M[a - 1][b - 1] = c;
            M[b - 1][a - 1] = c;
        }

        a = prim();

        if (a != -1)
            cout << a << endl;
        else
            cout << "No hay puentes suficientes\n";
    }
}
