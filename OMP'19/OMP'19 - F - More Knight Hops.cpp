#include <iostream>
using namespace std;

// Arrays de movimientos del caballo
int a[] = {1, 1, -1, -1, 2, 2, -2, -2};
int b[] = {2, -2, 2, -2, 1, -1, 1, -1};

void solve() {
    int n, m, x, y, cont = 0;
    cin >> n >> m;

    if (n < 5 && m < 5) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < 8; k++) {
                    x = i + a[k], y = j + b[k];
                    if (x >= 0 && x < n && y >= 0 && y < m)
                        cont++;
                }

        cout << cont / 2 << endl;
        return;
    }

    cout << (2*4 + 3*8 + (n-4)*4*2 + (m-4)*4*2 + 4*4 + (n-4)*6*2 + (m-4)*6*2 + (n-4)*(m-4)*8) / 2 << endl;
}

int main() {
    int casos;
    cin >> casos;
    while (casos--)
        solve();
}
