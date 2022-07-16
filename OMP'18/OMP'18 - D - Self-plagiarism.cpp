#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bits/stdc++.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <vector>

#define INF 200000000
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define REP(i, j) FOR(i, 0, j, 1)
// Abreviaciones tipos de datos
typedef unsigned long long int ull;
typedef long long int ll;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef pair<ll, ll> pll;
typedef pair<db, db> pdd;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef stringstream ss;

#define mp make_pair
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

void solve()
{
    string s;
    getline(cin, s);
    for (int i = s.size() - 1; i >= 1; i--)
    {
        unordered_map<string, int> us;
        set<int> is;
        for (int j = 0; j < s.size() - i + 1; j++)
        {
            string sub = s.substr(j, i);
            if (!us.count(sub)){
                us[sub] = j;
            }else{ // true
                is.insert(us[sub]);
            }
        }
        if(!is.empty()){           
            cout << s.substr(*is.begin(), i)<< endl;
            return;
        }
    }
    cout << endl;
}

int main()
{
    int casos;
    cin >> casos;
    string entrada;
    getline(cin, entrada);
    while (casos--)
    {
        solve();
    }
}