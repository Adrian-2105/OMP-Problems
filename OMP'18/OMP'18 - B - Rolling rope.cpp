#include <iostream>
#include <math.h>
using namespace std;

void solve() {
    double c, k, x;
    cin >> c >> k >> x;

    cout << (int) (x * sqrt(c*c + (k/x)*(k/x))) << endl;
}

int main() {
    int casos;
    cin >> casos;
    while (casos--)
        solve();
}
