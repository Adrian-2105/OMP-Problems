#include <iostream>
using namespace std;

bool is_prime(int n) {
    if (n % 2 == 0)
        return false;
    for (int i = 3; i < n / 2; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

void solve() {
    int n, x;
    cin >> n;

    for (int i = 49; i <= n; i++)
        if (is_prime(i) && i > n / 2) {
            cout << i << endl;
            break;
        }
}

int main() {
    int casos;
    cin >> casos;
    while (casos--)
        solve();
}
