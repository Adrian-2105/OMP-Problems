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

int sumDigits(int i){
    int res = 0;
    while(i!=0){
        res += i%10;
        i/=10;
    }
    return res;
}

int main(){
    int count = 0;
    int num = 16;
    vector<int> res;
    while(count <= 6){
        int square = num * num;
        int sum = sumDigits(square);
        if(sum % (int)(sqrt(sum)) == 0)
        {
            res.push_back(num);
            //cout << num << " " << square << endl;
            count ++;
        }else{
            count = 0;
            res.clear();
        }
        num ++;
    }
    for(auto x: res)
        cout << x << " " << x*x << endl;
    return 0;
}