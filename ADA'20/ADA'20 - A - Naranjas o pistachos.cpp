#include <iostream>

using namespace std;

void solve() {
    string s;
    int n;
    cin >> s >> n;
    if (s == "pistachos")
        n++;
    n = n % 2;
    if (n)
        cout << "pistachos\n";
    else
        cout << "naranjas\n";
}

int main() {
    int casos;
    cin >> casos;
    while (casos--)
        solve();
}
