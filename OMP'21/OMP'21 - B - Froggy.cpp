#include <bits/stdc++.h>
using namespace std;

#define INF 99999999

#define MAX 8
int a[] = {-1, -1, -1, -2, -2, -2, -1, -1};
int b[] = { 0, -1,  1, 0,  -1,  1, -2,  2};
int c[] = { 0,  0,  0, 1,  1,   1,  1,  1};

struct move {
    int i, j, k;
};

// i = -1 if error
struct move calc_move(int i, int j, int k, int t, int jumps, int cont) {
    i -= a[cont];
    j += b[cont];
    k -= c[cont];

    if (i < 0)
        i = t + i;
    else if (i > t)
        i = -1;

    if (j < 0)
        j = t + j;
    else if (j >= t)
        j = j % t;

    if (k < 0 || k > jumps)
        i = -1;

    return {i, j, k};
}

void solve() {
    // Input
    int t, jumps, l;
    cin >> t >> jumps >> l;
    vector<vector<int>> v(t+1, vector<int>(t));
    for (int i = 0; i < t; i++)
        v[0][i] = 0;
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < t; j++) {
            char c;
            cin >> c;
            v[i][j] = c - '0';
        }
    }

    // DP initialization
    int dp[t+1][t][jumps+1];
    memset(dp, 0, sizeof(dp));
    for (int j = 0; j < t; j++)
        for (int k = 0; k <= jumps; k++)
            dp[t][j][k] = v[t][j];
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++)
            for (int k = 0; k <= jumps; k++)
                dp[i][j][k] = INF;
    }

    // Tridimensional DP
    for (int i = t - 1; i >= 0; i--) {
        for (int j = 0; j < t; j++) {
            for (int k = 0; k <= jumps; k++) {

                if (k > 0)
                    dp[i][j][k] = dp[i][j][k-1];

                for (int move = 0; move < MAX; move++) {
                    struct move next = calc_move(i, j, k, t, jumps, move);
                    if (next.i == -1) continue;
                    dp[i][j][k] = min(dp[i][j][k], dp[next.i][next.j][next.k] + v[i][j]);
                }

            }
        }
    }


    // Search for the minimum
    int m = INF;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < t; j++) {
            for (int k = 0; k <= jumps; k++)
                m = min(m, dp[i][j][k]);
        }
    }

    if (m >= l)
        cout << "Froggy dies" << endl; 
    else
        cout << m << endl;

}

int main() {
    int c;
    cin >> c;
    while(c--) {
        solve();
    }
}