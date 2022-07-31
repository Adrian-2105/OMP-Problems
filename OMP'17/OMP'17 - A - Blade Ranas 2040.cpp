/*
 * Author: marcgil1
 * Date:   2022/07/31
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long             ll;
typedef pair<int, int>        ii;
typedef vector<ii>            vii;
typedef vector<int>           vi;
typedef vector<vector<int> >  vvi;
typedef vector<vector<ii> >   vvii;
typedef vector<char>          vc;
typedef vector<vector<char> > vvc;
typedef vector<ll>            vll;
typedef vector<vector<ll> >   vvll;

#define INF              1000000000
#define all(x)           begin((x)), end((x))
#define range(i, n0, nn) for (int(i) = (n0); (i) <= int(nn); (i) += 1)
#define fst(x)           get<0>(x)
#define snd(x)           get<1>(x)
#define trd(x)           get<2>(x)
#define fth(x)           get<3>(x)

ll   nxt()      { ll   x; cin >> x; return x; }
int  nxt_int()  { int  x; cin >> x; return x; }
char nxt_char() { char c; cin >> c; return c; }

template<typename T>
void print_vec(vector<T> const& xs, string_view name = "", string_view sep = "", std::ostream& os = cout) {
    if (not empty(name)) {
        os << name << ": ";
    }

    os << xs[0];
    range(i, 1, size(xs)-1) {
        os << sep << xs[i];
    }
    os << endl;
}

template<typename T>
void print_mat(vector<vector<T>> const& mat, string_view name = "", string_view sep = "", ostream& os = cout) {
    if (not empty(name)) {
        os << name << ": ";
    }
    
    for (auto row: mat) {
        for (auto x: row) {
            os << sep << x;
        }
        os << endl;
    }
}

const vii drc = { {-1, 0}, {-1, +1}, {0, +1}, {+1, +1}, {+1, 0}, {+1, -1}, {0, -1}, {-1, -1} };

ll num_r, num_c;

ll count_frogs(vvc& mat, ii pos, ii drc) {
    ll sum = 0ll;
    for (int r = fst(pos) + fst(drc), c = snd(pos) + snd(drc); r >= 0 and r < num_r and c >= 0 and c < num_c; r += fst(drc), c += snd(drc)) {
        if (mat[r][c] == '#') {
            break;
        } else if (mat[r][c] == 'R') {
            sum++;
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = nxt();
    while (t--) {
        num_r = nxt();
        num_c = nxt();
        vvc mat(num_r, vc(num_c, ' '));
        for (auto& row: mat) {
            cin.ignore();
            for (auto& cell: row) {
                cin >> cell;
            }
        }

        ii idx;
        ll res = -1;
        range(r, 0, num_r-1) {
            range(c, 0, num_c-1) {
                ll num_frogs = 0ll;

                if (mat[r][c] != '#') {
                    num_frogs += ll(mat[r][c] == 'R');
                    for (auto drcp: drc) {
                        num_frogs += count_frogs(mat, {r, c}, drcp);
                    }
                }

                if (num_frogs > res) {
                    idx = { r, c };
                    res = num_frogs;
                }
            }
        }

        cout << fst(idx) + 1 << " " << snd(idx) + 1 << endl;
    }
    return 0;
}
