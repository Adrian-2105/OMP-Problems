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

template<typename T>
void print_queue(T q) { // NB: pass by value so the print uses a copy
    while(!q.empty()) {
        std::cout << q.top()+1 << ' ';
        q.pop();
    }
    std::cout << '\n';
}

void print_vector(vector<int> v){
    for(int x : v) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

int main() {
   int numCases;
   cin >> numCases;
   for(int i = 0; i < numCases; i++) {
    long long altura = 0;
    cin >> altura;
    cout <<  ((altura *(altura-1))/2 - (altura-1)/2) + altura << endl;
   }
}