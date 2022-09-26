#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

vector<int> v(9, 0);

bool count(int a, int b, int c){
	set<int> s;
	
	int n = a;
	while(n > 0) {
		s.insert(n%10);
		n /= 10;
	}
	
	n = b;
	while(n > 0) {
		s.insert(n%10);
		n /= 10;
	}
	
	n = c;
	while(n > 0) {
		s.insert(n%10);
		n /= 10;
	}
	
	if (s.find(0) != s.end())
		return false;
	
	return s.size() == 9;
}

void print(int n) {
	stringstream ss;
	ss << n;
	string s;
	ss >> s;
	
	cout << s[0];
	for (int i = 1; i < s.size(); i++) {
		cout << " " << s[i];
	}
	cout << endl;
}


void solve() {
	vector<int> res;
	for(int i = 123; i < 987; i++){
		if (i * 3 > 987)
			break;
		if(count(i, i*2, i*3)){
			res.push_back(i);
		}
	}
	
	print(res[0]);
	print(res[0]*2);
	print(res[0]*3);
	
	for (int i = 1; i < res.size(); i++) {
		cout << endl;
		print(res[i]);
		print(res[i]*2);
		print(res[i]*3);
	}
}

int main() {
	solve();
}

