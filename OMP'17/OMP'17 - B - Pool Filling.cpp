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
#define read_vector(v, n) REP(i,n) {cin >> v[i];}
#define read_matrix(M, m, n) REP(i,m) REP(j,n) cin >> M[i][j]
#define read_line_SS(SS) string s; getline(cin, s); SS << s
#define print_array(a, n) REP(i,n) cout << a[i] << " "; cout << endl
#define print_vector(v) for (auto a : v) cout << a << " "; cout << endl
#define print_matrix(M, m, n) REP(i, m) {REP(j, n) cout << M[i][j]; cout << endl;}

void solve() {
    ll maxCapacity;
    double targetTemperature;
    cin >> maxCapacity >> targetTemperature;
    ll numJars;
    cin >> numJars;
    vi capacityJars(numJars), temperatureJars(numJars);
    for (ll i = 0; i < numJars; i++)
        cin >> capacityJars[i] >> temperatureJars[i];


    double topTemperature = INF, topI, topJ;
    for (ll i = 0; i < numJars; i++) {
        ll currentCapacity = 0;
        double temperaturePond = 0;
        for (ll j = i; j < numJars; j++) {
            currentCapacity += capacityJars[j];
            temperaturePond += temperatureJars[j] * capacityJars[j];
            if (currentCapacity > maxCapacity) break;
            if (currentCapacity * 2 >= maxCapacity) {
                if (abs(temperaturePond / currentCapacity - targetTemperature) < abs(topTemperature - targetTemperature)) {
                    topTemperature = temperaturePond / currentCapacity;
                    topI = i;
                    topJ = j;
                }
            }
        }
    }

    if (abs(topTemperature - targetTemperature) > 5)
        cout << "Not possible" << endl;
    else
        cout << topI << " " << topJ << endl;

}

int main() {
    int casos;
    cin >> casos;
    while (casos--) {
        solve();
    }
}