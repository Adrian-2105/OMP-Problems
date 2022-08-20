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
     cout << setprecision(4) << fixed; 
    while(true){
        string line;
        getline(cin, line);
        if(line == "0"){
            break;
        }
        vector<char> references;
        int count = 0;
        int distance = 0;
        for(int i = 0; i < line.size(); i++){            
            for(int j = 0; j < references.size(); j++){ 
                if(line[i] == references[j]){
                    distance += references.size() - 1 -j; 
                    count++;
                    references.erase(references.begin() + j);
                    break;
                }
            }
                references.push_back(line[i]);
            
        }
        if(count == 0){
            cout << "NaN" << endl;
        }else{
            cout << (double)distance/count << endl;
        }
    }
}