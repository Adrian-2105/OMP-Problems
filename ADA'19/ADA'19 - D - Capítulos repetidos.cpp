#include <iostream>
#include <map>


using namespace std;

void solve() {
    int n, res = 0;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];

    map<int,int> last;
    int i = 0;
    for (int j = 0; j < n; j++) {
        if (last[v[j]])
            i = max(i, last[v[j]]);
        res = max(res, j - i + 1);
        last[v[j]] = j + 1;
    }

    cout << res << endl;
}

int main() {
    int casos;
    cin >> casos;
    while (casos--)
        solve();
}
