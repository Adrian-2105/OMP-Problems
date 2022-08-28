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

vector<vector<int>> dp(1000, vector<int>(1000));

int rd(vector<int> v, int lower, int upper);

int nl(vector<int> & v, int lower, int upper){
    if(lower == upper){
        return v[lower];
    }
    if(dp[lower][upper]!=-1){
        return dp[lower][upper];
    }
    int res =  max(v[lower] + rd(v, lower+1, upper), v[upper] + rd(v, lower, upper-1));
    dp[lower][upper] = res;
    return res;
}

int rd(vector<int> v, int lower, int upper){
    if(lower == upper){
        return 0;
    }
    if(v[lower] > v[upper]){
        return nl(v, lower+1, upper);
    }
    if(v[lower] < v[upper]){
        return nl(v, lower, upper-1);
    }
    return min(nl(v, lower+1, upper), nl(v, lower, upper-1));
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i <n; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v[i] = num;
    }
    cout << min(nl(v, 0, n-1), rd(v, 0, n-1))<< endl;
}

int main(){
    int cases;
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    
}