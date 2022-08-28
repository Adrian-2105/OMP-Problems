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

void solve() {
    vector<long long> v;
    for(int i=0; i<4; i++) {
        long long aux;
        cin >> aux;
        v.push_back(aux);
    }
    sort(v.begin(), v.end(), greater<long long>());
    if(v[0] == v[1] && v[2] == v[3] && v[0] == v[2])
        cout << "square" << endl;
    else if(v[0] == v[1] && v[2] == v[3]){
        cout << "rectangle" << endl;
    }else if(v[0]< v[1] + v[2] + v[3]){
        cout << "quadrangle" << endl;
    }else{
        cout << "banana" << endl;
    }
}

int main(){
    int cases = 0;
    cin >> cases;
    while (cases--){
        solve();
    }
}