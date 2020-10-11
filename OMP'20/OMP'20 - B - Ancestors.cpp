#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define REP(i, j) FOR(i, 0, j, 1)

typedef vector<int> vi;

#define all(x) (x).begin(), (x).end()

#define read_array(v, n) REP(i,n) cin >> v[i]


int p2(int p) {
    int n = 1;
    for (int i = 0; i < p; i++)
        n *= 2;
    return n;
}

int nodos(int nivel) {
    return p2(nivel) - 1;
}

int nv(int n, int niveles) {
    int p = 0;
    while (p2(p) / n == 0)
        p++;
    if (p2(p) % n != 0)
        p--;
    return nodos(niveles - p );
}

bool des(int a, int b) {
    if (a > b)
        return false;
    if (a == b)
        return true;
    return des(a*2, b) || des(a*2+1, b);
}

void solve() {
    int nivel, desc, n;
    cin >> nivel >> desc;
    vi v(desc);
    read_array(v, desc);
    sort(all(v));
    REP(i, v.size()) {
        for (int j = i + 1; j < v.size(); j++){
            if (des(v[i], v[j])) {
                v.erase(v.begin() + j);
                j--;
            }
        }
    }

    n = nodos(nivel);

    REP(i,v.size()) {
        n -= nv(v[i], nivel);
    }

    cout << "People in the family tree: " << n << endl;
}

int main() {
    int casos;
    cin >> casos;
    while (casos--) {
        solve();
    }
}
