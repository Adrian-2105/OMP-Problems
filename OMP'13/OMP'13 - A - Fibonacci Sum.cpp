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

// precalculated just looking how the sucesion works
#define LOOP 300
#define LOOP_SUM (7448 + 7352)

int main() {
    ll casos;
    cin >> casos;

    vi v(LOOP+1);
    v[1] = 1;
    v[2] = 1;
    for (int i = 3; i < v.size(); i++)
        v[i] = (v[i-1] + v[i-2]) % 100;

    while (casos--) {
        ll n, m;
        cin >> n >> m;

        ll sum = 0;

        ll it_n = (n / LOOP);
        ll it_m = (m / LOOP);

        if (it_m > it_n) {
            
            // rest of the loop for n
            for (int i = n % LOOP; i <= LOOP; i++)
                sum += v[i];

            // direct calculation of intermediate results
            sum += (it_m - it_n - 1) * LOOP_SUM;

            // rest oif loop for m
            for (int i = 0; i <= m % LOOP; i++)
                sum += v[i];
        }
        else {
            for (int i = n % LOOP; i <= m % LOOP; i++)
                sum += v[i];
        }


        cout << sum << endl;
    }
}
