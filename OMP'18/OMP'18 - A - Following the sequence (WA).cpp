#include <bits/stdc++.h>
using namespace std;

#define INF 200000000
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define REP(i, j) FOR(i, 0, j, 1)
// Abreviaciones tipos de datos
typedef unsigned long long int ull;
typedef long long int ll;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef pair<ll, ll> pll;
typedef pair <db, db> pdd;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<pair<int, int>> vii;
typedef stringstream ss;

#define mp make_pair
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

// Funciones macro
#define read_array(v, n) REP(i,n) cin >> v[i]
#define read_vector(v, n, aux) REP(i,n) {cin >> aux; v.pb(aux);}
#define read_matrix(M, m, n) REP(i,m) REP(j,n) cin >> M[i][j]
#define read_line_SS(SS) string s; getline(cin, s); SS << s
#define print_array(a, n) REP(i,n) cout << a[i] << " "; cout << endl
#define print_vector(v) for (auto a : v) cout << a << " "; cout << endl
#define print_matrix(M, m, n) REP(i, m) {REP(j, n) cout << M[i][j]; cout << endl;}


/*
EL JUEZ OFRECE WRONG ANSWER (WA) PARA ESTE PROBLEMA

Tal vez sea un error en la especificación del enunciado, pues con 4 dígitos
no se pueden diferenciar todas las secuencias

Ej: 2 3 5 8 puede ser tanto "add more" como "fibbonaci"

También, las operaciones con decimales con posterior transformación a entero pueden dar lugar
a errores según cómo esté implementada la solución en el juez
*/

void solve() {
    ll diff;
    vector<ll> v(4);
    REP(i, 4) cin >> v[i];

    // constant
    diff = v[1] - v[0];
    if (v[1] == v[0] + diff &&
        v[2] == v[1] + diff &&
        v[3] == v[2] + diff) {
        cout << v[3] + diff << endl;
        return;
    }

    // add more
    diff = v[1] - v[0];
    if (v[1] == v[0] + diff &&
        v[2] == v[1] + diff + 1 &&
        v[3] == v[2] + diff + 2) {
        cout << v[3] + diff + 3 << endl;
        return;
    }

    // fibbonaci
    if (v[2] == v[0] + v[1] && v[3] == v[2] + v[1]) {
        cout << v[2] + v[3] << endl;
        return;
    }

    // multiply
    if (v[0] != 0 && abs(v[1] / v[0]) > 0) {
        diff = v[1] / v[0];
        if (v[1] == v[0] * diff &&
            v[2] == v[1] * diff &&
            v[3] == v[2] * diff) {
            cout << v[3] * diff << endl;
            return;
        }
    } else if (v[1] != 0 && abs(v[0] / v[1]) > 0) {
        diff = v[0] / v[1];
        if (v[0] == v[1] * diff &&
            v[1] == v[2] * diff &&
            v[2] == v[3] * diff) {
            cout << v[3] / diff << endl;
            return;
        }
    } else if (v[1] == 0 && v[2] == 0 && v[3] == 0) {
        cout << 0 << endl;
        return;
    }


    cout << 42 << endl;
}

int main() {
    int casos;
    cin >> casos;
    while (casos--) {
        solve();
    }
}