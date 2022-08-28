#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    unsigned long long num;
    cin >> num;
    cout << int(floor((-1 + sqrt(1+8*num))/2)) << endl;
}

int main(){
    int cases; 
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}