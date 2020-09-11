#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    // Cálculo de las soluciones
    ll soluciones[81];
    ll m = 1, p = 0;
    ll next_m, next_p;
    for (int i = 1; i < 81; i++) {
        soluciones[i] = m + p;
        next_m = m + p;
        next_p = m;
        m = next_m, p = next_p;
    }

    int n;
    cin >> n;
    while (n != 0) {
        cout << soluciones[n] << endl;
        cin >> n;
    }

}
