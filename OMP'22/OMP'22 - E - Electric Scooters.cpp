#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	while(n != 0) {
		ll c, bat, k;
		cin >> c >> bat >> k;
		ll walk = 0;
		
		for (ll i = 0; i < n; i++) {
			
			int x;
			cin >> x;
			if (x < 0) {
				bat = min(c, bat - x);
			}
			else if (x + k > bat) {
				walk++;
				bat = 0;
			}
			else {
				bat -= (x + k);
			}
		}
		
		cout << "WALK " << walk << endl;
		cout << "BATTERY " << bat << endl;
		
		
		
		
		
		
		cin >> n;
	}
}

