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

double fact(double n){
    if(n == 0) return 1;
    return fact(n-1) * n;
}

void solve(){
    int n;
    cin >> n;
    n = n*2 -1 ;
    double p;
    cin >> p;
    int wins = (n-1)/2+1;
    double res =  0;
    for (int i = wins ; i <= n ; i++)
    {
        res += fact(n)/(fact(i)*fact(n-i)) * pow(p, i - (n - i)) * pow((1-p)*p, n - i);
        //cerr << i << " " << p  <<" "<<fact(n)/(fact(i)*fact(n-i)) * pow(p, i) * pow(1-p, n - i) << " " <<  pow(p*(1-p), i) * pow(p, n - (n - i))<< " " << pow(1-p, n-i)  <<endl;
    }
    cout << res << endl;
    //cerr << endl;
    
}

int main() {
    cout << setprecision(2) << fixed;
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
    return 0;

}