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

int diff(string &s1, string &s2) {
    int t = 0;
    for (int i = 0; i < s1.size(); i++)
        if (s1[i] != s2[i])
            t++;
    return t;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<string> v(n);
        for (auto &s: v)
            cin >> s;
  
        swap(v[1], v[n-1]);

        for (int i = 0; i < n - 2; i++) {
            for (int j = i+1; j < n - 1; j++) {
                if (diff(v[i], v[j]) == 1) {
                    swap(v[i + 1], v[j]);
                    break;
                }
            }
        }

        for (auto s : v)
            cout << s << endl;

    }
}
