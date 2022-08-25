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

void solve(){
    string cadena;
    getline(cin, cadena);
    getline(cin, cadena);
    vector<char> respuesta(cadena.length()-2, 0);
    for(int i = 0; i < 8; i++){
        getline(cin, cadena);
        for(int j=1; j < cadena.size() - 1; j++){
            if(cadena[j] == '\\'){
                respuesta[j-1] += 1 << i;
            }
        }
    }
    for (char x: respuesta)
    {
        cout << x;
    }
    cout << endl;
    getline(cin, cadena);
    
}  

int main(){
    int cases;
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    
}