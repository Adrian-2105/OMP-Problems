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
    string cad;
    cout << setprecision(2) << fixed;
    while(getline(cin, cad)){
        stringstream ss;
        ss << cad;
        if(cad == ""){
            cout << 4 << " " << (1.0/6.0) << endl;
            continue;
        }
        int num;
        float maxim = 0, counter = 0;
        while(ss >> num){
            counter++;
            maxim = fmax(num, maxim);
        }
        if(maxim <= 4){
            cout << 4 <<" " << (1/pow(4, counter)) / (1/pow(4, counter) + 1/pow(6, counter) + 1/pow(8, counter) + 1/pow(10, counter) + 1/pow(12, counter) + 1/pow(20, counter)) << endl;
        }else if (maxim <= 6)
        {
            cout << 6 << " " << (1/pow(6, counter)) / (1/pow(6, counter) + 1/pow(8, counter) + 1/pow(10, counter) + 1/pow(12, counter) + 1/pow(20, counter)) << endl;          
        }else if (maxim <= 8)
        {
            cout << 8 << " " << (1/pow(8, counter)) / (1/pow(8, counter) + 1/pow(10, counter) + 1/pow(12, counter) + 1/pow(20, counter)) << endl;  
        }else if (maxim <= 10)
        {
            cout << 10 << " " << (1/pow(10, counter)) / (1/pow(10, counter) + 1/pow(12, counter) + 1/pow(20, counter)) << endl;           
        }else if (maxim <= 12)
        {   
            cout << 12 <<" " << (1/pow(12, counter)) / (1/pow(12, counter) + 1/pow(20, counter)) << endl;           
        }else
        {
            cout << 20 << " " << 1.00 << endl;
        }
    }
    return 0;
}