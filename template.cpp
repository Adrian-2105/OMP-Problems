#include <bits/stdc++.h>
using namespace std;

// Datatypes
using db = double;
using ldb = long db;
using ll = long long;
using ull = unsigned ll;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vii = vector<ii>;
using ss = stringstream;

// Macro functions
#define INF 1e9
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define REP(i, j) FOR(i, 0, j, 1)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define sz(x) (x).size()
#define mp make_pair

// Template functions
template<typename T>
void readVector(vector<T> &v, ull n = 0) {
    if (n > 0) v.resize(n);
    for (auto& elem: v) cin >> elem;
}

template<typename T>
void readMatrix(vector<vector<T>> &v, ull n = 0, ull m = 0) {
    if (m == 0 && n != 0) {
        cerr << "readMatrix bad initialized" << endl;
        exit(1);
    }

    if (n > 0) n = v.size();
    for (auto& row: v) {
        if (m > 0) row.resize(m);
        for (auto& elem: row) cin >> elem;
    } 
}

string readLine() {
    string s;
    getline(cin, s);
    return s;
}

template<typename T>
void printVector(vector<T> &v) {
    for (auto& elem: v) cout << elem << " ";
    cout << endl;
}

template<typename T>
void printMatrix(vector<vector<T>> &v) {
    for (auto& row: v) {
        for (auto& elem: row) 
            cout << elem << " ";
        cout << endl;
    }

}




void solve() {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c;
    cin >> c;
    while(c--) {
        solve();
    }
}
