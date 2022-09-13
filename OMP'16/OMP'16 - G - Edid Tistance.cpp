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
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    if (s1 == " " || s1 == "" || s2 == " " || s2 == "") {
        cout << max(s1.size(), s2.size()) << endl;
        return;
    }

    int dp[s1.size()][s2.size()];

    for (int i = 0, k = 0, f = 1; i < s1.size(); i++) {
        if (s2[0] != s1[i] || !f)
            dp[i][0] = ++k;
        else {
            f = 0;
            dp[i][0] = k;
        }
    }
    for (int j = 0, k = 0, f = 1; j < s2.size(); j++) {
        if (s1[0] != s2[j] || !f)
            dp[0][j] = ++k;
        else {
            f = 0;
            dp[0][j] = k;
        }
    }

    for (int i = 1; i < s1.size(); i++) {
        for (int j = 1; j < s2.size(); j++) {
            if (s1[i] == s2[j])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
        }
    }

    cout << dp[s1.size()-1][s2.size()-1] << endl;
}

int main() {
    int c;
    cin >> c;
    cin.ignore();
    while(c--) {
        solve();
    }
} 
