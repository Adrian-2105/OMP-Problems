#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
#define pb(x) push_back(x)

int objetive, bars, aux;

void solve() {
    // Lectura de la entrada
    cin >> objetive >> bars;
    vi v;
    v.pb(0);
    for (int i = 0; i < bars; i++) {
        cin >> aux;
        v.pb(aux);
    }

    // Matriz PD
    bool DP[bars+1][objetive+1];
    // Casos base
    for (int i = 0; i <= bars; i++)
        DP[i][0] = true;
    for (int j = 1; j <= objetive; j++)
        DP[0][j] = false;

    for (int i = 1; i <= bars; i++)
        for (int j = 1; j <= objetive; j++)
            DP[i][j] = DP[i - 1][j] || (j - v[i] >= 0 && DP[i-1][j - v[i]]);

    if (DP[bars][objetive])
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    int casos;
    cin >> casos;
    while (casos--)
        solve();
}
