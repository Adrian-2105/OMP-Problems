#include <bits/stdc++.h>
using namespace std;



void solve() {
    // input
    int m, c;
    cin >> m >> c;
    vector<vector<int>> v(c);
    for (int i = 0; i < c; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int n;
            cin >> n;
            v[i].push_back(n);
        }
    }

    // dp initialization
    bool dp[c][m+1];
    memset(dp, false, sizeof(dp));
    for (int i = 0; i < v[0].size(); i++) {
        if (v[0][i] <= m)
            dp[0][v[0][i]] = true;
    }

    // dp, each position of matrix
    for (int i = 1; i < c; i++) {
        for (int j = 0; j <= m; j++) {
            
            // try all reacheable amounts using all combinations
            for (int k = 0; k < v[i].size(); k++) {
                if (j - v[i][k] >= 0)
                    dp[i][j] |= dp[i-1][j - v[i][k]];
            }
            
        }
    }

    // check if there is available some amount less that the target money
    for (int j = m; j >= 0; j--) {
        if (dp[c-1][j]) {
            cout << j << endl;
            return;
        }
    }
    cout << "no solution" << endl;
}

int main() {
    int c;
    cin >> c;
    while(c--)
        solve();
}