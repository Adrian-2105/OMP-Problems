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

vector<long long> sol(200000,1);
int main(){
    sol[0] = 543862;
    for(int i=1;i<200000;i++){
        sol[i] = (sol[i-1] * sol[0]) % 1000007;
        //cerr << sol[i] << endl;
    }
    int N;
    cin >> N;
    while(N--){
        int num; 
        cin >> num;
        cout << sol[num-1] << endl;
    }
    return 0;
}