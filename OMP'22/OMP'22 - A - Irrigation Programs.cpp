#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

int get_time() {
	char c;
	int  h, m;

	cin.ignore();
	cin >> c >> h;
	cin.ignore();
	cin >> m;

	int res = 0;
	switch (c) {
		case 'L': res = 0; break;
		case 'M': res = 1; break;
		case 'X': res = 2; break;
		case 'J': res = 3; break;
		case 'V': res = 4; break;
		case 'S': res = 5; break;
		case 'D': res = 6; break;
	}

	res = res * 24 * 60 + h * 60 + m ;
	return res;
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> res(m, 0);

	while (n--) {
		int beg = get_time();
		int end = get_time();

		for (int i = beg; i < end; i++)
			if (i < m)
				res[i] = 1;

	}
	for (int x: res)
		cout << x;
	cout << endl;
}

