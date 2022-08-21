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
    int day;
    cin >> day;
    while(day != 0){
        string month;
        cin >> month;
        //cout << day << month << endl;
        int sol = 0;
        if(month == "Aug"){
            sol = 143;
        }else if (month == "Sep")
        {
            sol = 112;
        }else if (month == "Oct")
        {
            sol = 82;
        }else if (month == "Nov")
        {
            sol = 51;
        }else if (month == "Dec")
        {
            sol = 21;
        }else{
            return 1;
        }

        sol -= day;
        
        if(sol  <= 0){
            cout << "Winter is here" << endl;
        }else{
            cout << sol << " days to winter" << endl; 
        }
        
        
        cin >> day;
    }
    return 0;
}