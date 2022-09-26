#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

#define fst(x) (get<0>(x))
#define snd(x) (get<1>(x))

void print_sol(vector<char> order, unordered_map<char, vector<tuple<ll, unordered_set<ll>>>> deltas) {
	for (auto c: order) {
		auto vec = deltas[c];

		cout << c << ' ' << size(vec);
		
		if (size(vec) > 1) {
			unordered_map<ll, ll> freqs;
			
			for (auto [_, diffs]: vec)
				for (auto diff: diffs)
					freqs[diff]++;
			
			vector<tuple<ll, ll>> candidates;
			for (auto [diff, freq]: freqs)
				candidates.emplace_back(diff, freq);

			sort(all(candidates),
				[] (auto t1, auto t2) {
					if (snd(t1) > snd(t2)) {
						return true;
					} else if (snd(t1) == snd(t2)) {
						if (abs(fst(t1)) < abs(fst(t2))) {
							return true;
						} else if (abs(fst(t1)) == abs(fst(t2))) {
							return fst(t1) >= 0;
						} else {
							return false;
						} 
					} else {
						return false;
					}
				}
			);

			cout << ' ' << fst(candidates[0]) << ' ' << snd(candidates[0]);
		}
		cout << endl;
	}
}

int main() {
	char c;
	ll num;

	unordered_map<char, vector<tuple<ll, unordered_set<ll>>>> deltas;
	unordered_set<char> seen_chars;
	vector<char>        order;

	while (true) {
		cin >> c;
	
		if (c == '.') {
			print_sol(order, deltas);
			cout << ".\n";
			seen_chars.clear();
			order.     clear();
			deltas.    clear();
			cin.ignore();
			cin >> c;
		} else if (c == '#') {
			print_sol(order, deltas);
			cout << "#\n";
			return 0;
		}

		if (seen_chars.find(c) == seen_chars.end()) {
			seen_chars.insert   (c);
			order.     push_back(c);
		}
		cin >> num;

		auto& dc = deltas[c];
		dc.emplace_back(num, unordered_set<ll>());
		if (size(dc) >= 4) {
			ll diff = - num + fst(dc[size(dc)-4]);
			if (diff != 0)
				snd(dc.back()).insert(-diff);
		}
		if (size(dc) >= 3) {
			ll diff = - num + fst(dc[size(dc)-3]);
			if (diff != 0)
				snd(dc.back()).insert(-diff);
		}
		if (size(dc) >= 2) {
			ll diff = - num + fst(dc[size(dc)-2]);
			if (diff != 0)
				snd(dc.back()).insert(-diff);
		}
	}
}

