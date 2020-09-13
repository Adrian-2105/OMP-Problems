#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define REP(i, j) FOR(i, 0, j, 1)
#define pb(x) push_back(x)

int n, aux;

bool ordenar_plantas(int a, int b) {
    return abs(a) < abs(b);
}

void solve() {
    // Lectura entrada
    vector<int> v;
    cin >> n;
    REP(i, n) {
        cin >> aux;
        v.pb(aux);
    }

    sort(v.begin(), v.end(), ordenar_plantas);

    int rest = 0;
    for (int i = 0; i < n - 1; i++)
        if ((v[i+1] > 0 && v[i] > 0) || ((v[i+1] < 0 && v[i] < 0)))
            rest++;

    cout << n - rest << endl;
}

int main() {
    int casos;
    cin >> casos;
    while (casos--)
        solve();
}
