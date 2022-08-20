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

int main(){
    int N;
    cin >> N;
    string line;
    getline(cin, line);
    while(N--){
        getline(cin, line);
        stack<int> q;
        int sol = 0;
        for(int i = 0 ; i < line.size() ; i++){ 
            if(line[i] == '\\'){
                q.push(i);
            }
            if(line[i] == '/' && q.size() != 0){
                sol += i - q.top() ;
                q.pop();
            }
        }
        cout << sol << endl;    
    }
}