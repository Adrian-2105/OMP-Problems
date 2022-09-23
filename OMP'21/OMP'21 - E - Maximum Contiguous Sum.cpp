#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &a: v) cin >> a;

    pair<ll,pair<ll,ll>> sol = {v[0], {0, 0}};

    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (int j = 0; j < n; j++) {
            sum += v[(i+j)%n];

            if (sum > sol.first || 
                (sum == sol.first && i < sol.second.first) || 
                (sum == sol.first && i == sol.second.first && j < sol.second.second))
                sol = {sum, {i, j}};
        }
    }

    cout << sol.first << " " << sol.second.first+1 << " " << sol.second.second+1 << endl;
}

int main() {
    ll c;
    cin >> c;
    while(c--) solve();
}