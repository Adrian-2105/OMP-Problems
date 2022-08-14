#include <bits/stdc++.h>
using namespace std;

vector<int> pr;


void fill_primes() {
    int lp[int(1e6+1)] = {0};
    pr.push_back(1);
    
    for (int i = 2; i < 100000; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }

        for (int j = 1; j < int(pr.size()) and pr[j] <= lp[i] and i*pr[j] <= 100000; j++) {
            lp[i*pr[j]] = pr[j];
        }
    }
}


void solve() {
    int n, k;
    cin >> n >> k;
    k++;

    int DP[150][6000] = {0};
    for (int i = 0; i < n; i++)
        DP[i][0] = 0;
    for (int j = 1; j < k; j++)
        DP[0][j] = j;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < k; j++) {
            if (j - pr[i] >= 0) {
                DP[i][j] = min(DP[i-1][j], DP[i][j - pr[i]] + 1);
            }
            else {
                DP[i][j] = DP[i-1][j];
            }
        }
    }

    cout << DP[n-1][k-1] << endl;
}


int main() {
    fill_primes();
    int casos;
    cin >> casos;
    while(casos--) {
        solve();
    }
}