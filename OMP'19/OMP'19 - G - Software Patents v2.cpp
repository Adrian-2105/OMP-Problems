#include <iostream>
#include <vector>

using namespace std;

#define pb(x) push_back(x)
#define mp make_pair

bool mayor_izq(pair<string, int> &a, pair<string, int> &b) {
    if (a.second > b.second)
        return true;
    else if (b.second > a.second)
        return false;
    else if (a.first < b.first)
        return true;
    return false;
}

bool contiene_clave(vector<pair<string, int>> &v, string &s) {
    for (auto p : v)
        if (p.first == s)
            return true;
    return false;
}

void solve() {
    // Lectura de la entrada
    int n;
    cin >> n;
    string cadenas[n];
    for (int i = 0; i < n; i++)
        cin >> cadenas[i];

    // Resolución del problema
    vector<pair<string, int>> soluciones;

    // Búsqueda de todas las subcadenas de longitud 3
    for (int i = 0; i < n; i++) {
        // Conteo de la aparición de cada subcadena
        for (int j = 0; j + 2 < cadenas[i].length() - 1; j++) {
            string clave = cadenas[i].substr(j, 3);
            // Si no se ha procesado ya la nueva subcadena procedemos a su procesamiento
            if (!contiene_clave(soluciones, clave)) {
                // Añadimos la nueva clave
                soluciones.pb(mp(clave, 0));
                // Nota: no tiene sentido empezar por los anteriores pues la cadena a�n no habr� aparecido
                // Tratamos la primera línea por separado
                for (int jk = j; jk + 2 < cadenas[i].length() - 1; jk++)
                    // Añadimos al contador
                    if (clave == cadenas[i].substr(jk, 3))
                        soluciones[soluciones.size() - 1].second++;

                for (int ik = i + 1; ik < n; ik++)
                    for (int jk = 0; jk + 2 < cadenas[ik].length() - 1; jk++)
                        // Añadimos al contador
                        if (clave == cadenas[ik].substr(jk, 3))
                            soluciones[soluciones.size() - 1].second++;
            }
        }
    }

    // Búsqueda del mayor en las soluciones
    pair<string, int> mayor = mp("", 0);
    for (auto p : soluciones)
        if (mayor_izq(p, mayor))
            mayor = p;

    // Impresión de la solución
    cout << "PATENT " << mayor.first << " AND WIN " << mayor.second * 1000 << " EUROS!\n";
}

int main() {
    int casos;
    cin >> casos;
    while (casos--) {
        solve();
    }
}

