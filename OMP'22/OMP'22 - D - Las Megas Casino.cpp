#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

vector<ll> v;

int me(int i, int j);

int casino(int i, int j){
	if(i == j) return 0;
	if(v[i] > v[j]) return me(i+1, j);
	if(v[i] < v[j]) return me(i, j-1);
	return min(me(i+1, j), me(i, j-1));
}

int me(int i, int j){
	if(i == j) return v[i];
	return max(casino(i+1, j) + v[i], casino(i,j-1) + v[j]);
}

void solve() {
	int count = 0;
	cin >> count;
	int total = count;
	v.clear();
	while(count--){
		int aux;
		cin >> aux;
		v.push_back(aux);
	}
	cout <<  min(me(0,total-1), casino(0, total-1)) << endl;
}

int main() {
	int c;
	cin >> c;
	while(c--) solve();
}

