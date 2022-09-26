#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

long long get_time() {
	char c;
	long long  h, m, s;

	cin.ignore();
	cin >> c >> h;
	cin.ignore();
	cin >> m;
	cin.ignore();
	cin >> s;

	long long res = 0;
	switch (c) {
		case 'L': res = 0; break;
		case 'M': res = 1; break;
		case 'X': res = 2; break;
		case 'J': res = 3; break;
		case 'V': res = 4; break;
		case 'S': res = 5; break;
		case 'D': res = 6; break;
	}

	res = res * 24 * 60 * 60 + h * 60 * 60 + m * 60 + s;
	return res;
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<ll> begs(n);
	vector<ll> ends(n);

	for (int i = 0; i < n; i++) {
		begs[i] = get_time();
		ends[i] = get_time();
	}

	sort(all(begs));
	sort(all(ends));

	int depth = 0;
	int b_idx = 0;
	int e_idx = 0;
	for (int i = 0; i < m; i++) {
		while (e_idx < size(ends) and ends[e_idx] <= i) {
			e_idx++;
			depth--;
		}
		while (b_idx < size(begs) and begs[b_idx] <= i) {
			b_idx++;
			depth++;
		}
		if (depth > 0)
			cout << '1';
		else
			cout << '0';
	}
	cout << endl;
}


