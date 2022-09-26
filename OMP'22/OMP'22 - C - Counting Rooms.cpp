#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a;
    cin >> a;
    set<pair<int,int>> v;
    for (int i = 0; i < a; i++) {
        int x, y;
        cin >> x >> y;
        v.insert({x, y});
        cin >> x >> y;
        v.insert({x, y});
    }

    cout << -(int(v.size()) - a - 1) << endl;
}

int main() {
    int c;
    cin >> c;
    while(c--) solve();
}