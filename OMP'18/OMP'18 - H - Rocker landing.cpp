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

void solve() {
    ll fuel, height;
    cin >> fuel >> height;
    vector<ll> wind(height+1, 0);
    for (ll i = 0; i < height; i++)
        cin >> wind[i];

    ll end_position = accumulate(wind.begin(), wind.end(), 0);
    vector<ll> displacement(height+1, 0), position(height+1, 0);
    position[height] = end_position;
    ll current_position = 0;

    for (ll i = 0; i < wind.size(); i++) {
        displacement[i] = end_position - current_position; // relative displacement for each level 
        position[i] = current_position; // current default position for each level
        current_position += wind[i];
    }

    ll minimum_position = end_position, turbo_start = 0, turbo_fuel = 0;
    for (ll i = 0; i < wind.size() - 1; i++) { // trying to use turbo in each level
        for (ll j = 1; j <= fuel && i - j >= 0; j++) { // and all combinations of fuel
            ll landing_position = position[i] + 2*(position[i] - position[i - j]) + displacement[i]; // position where rocket will land after turbo

            // cout << endl << "at " << i << " with turbo " << j << " reach landing_position: " << landing_position << endl;
            // cout << "position: " << position[i] << " displacement: " << displacement[i] << endl;
            // cout << "position at high turbo: " << position[i-j] << endl;

            if (abs(landing_position) < abs(minimum_position) || (abs(landing_position) == abs(minimum_position) && j < turbo_fuel)) { // update minimum record
                minimum_position = abs(landing_position);
                turbo_start = i;
                turbo_fuel = j;
            }
        }
    }

    cout << turbo_start << " " << turbo_fuel << " " << minimum_position << endl;
}

int main() {
    int casos;
    cin >> casos;
    while (casos--) {
        solve();
    }
}
