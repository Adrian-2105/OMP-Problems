#include <iostream>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && a == c)
        cout << "equilatero\n";
    else if (a != b && b != c && a != c)
        cout << "escaleno\n";
    else
        cout << "isosceles\n";
}

int main() {
    int casos;
    cin >> casos;
    while (casos--)
        solve();
}
