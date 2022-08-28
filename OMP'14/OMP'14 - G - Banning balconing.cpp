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
    double L, D, H, V;
    cin >> L >> D >> H >> V;
    L /= 1000.0;
    D /= 1000.0;
    H /= 1000.0;
    V /= 1000.0;
    double pos = V * sqrt(H * 2 / 9.81);
    if(pos < D - 0.5){
        cout << "FLOOR"<< endl;
    }else if (pos <= D + 0.5)
    {
        cout << "EDGE" << endl;
    }else if (pos < D + L - 0.5)
    {
        cout << "POOL" << endl;
    }else if (pos <= D + L + 0.5)
    {
        cout << "EDGE" << endl;
    }else{
        cout << "FLOOR" << endl;
    }    
}

int main(){
    int cases;
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    
}