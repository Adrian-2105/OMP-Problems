/*
 * Author: marcgil1
 * Date:   2022/08/16
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
#define edge(u, v)       adj[u].push_back(v); adj[v].push_back(u);
#define edge_uni(u, v)   adj[u].push_back(v);

ll   nxt()      { ll   x; cin >> x; return x; }
int  nxtu()     { int  x; cin >> x; return x - 1; }
int  nxt_int()  { int  x; cin >> x; return x; }
char nxt_char() { char c; cin >> c; return c; }

template<typename T>
void print_vec(vector<T> const& xs, string_view name = "", string_view sep = " ", std::ostream& os = cout) {
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

const vii drc = { {-1, 0}, {+1, 0}, {0, -1}, {0, +1} };

int constexpr alph_size = 'z' - 'a' + 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = nxt();
    while (t--) {
        
        // Input, graph building and check if there exists an eulerian path
        int m = nxt();

        vi  deg_in (alph_size, 0),
            deg_out(alph_size, 0);
        int init_u = numeric_limits<int>::max();
        array<vector<string>, alph_size> dict;
        range(_, 1, m) {
            string w; cin >> w;
            int u = w.front() - 'a',
                v = w.back()  - 'a';
            deg_out[u]++;
            deg_in [v]++;
            init_u = min(init_u, u);
            dict[u].push_back(w);
        }

        for (auto& words: dict)
            sort(all(words), greater<string>());

        bool is_eulerian = true;
        range(u, 0, alph_size-1)
            if (deg_in[u] != deg_out[u])
                is_eulerian = false;

        if (not is_eulerian) {
            cout << "No way\n";
            continue;
        }

        
        // Hierholzer algorithm to print the eulerian path
        vi order;
        vector<string> res;
        stack<pair<int, string>> st; st.emplace(init_u, "");
        while (not empty(st)) {
            auto [u, w] = st.top();
            if (not empty(dict[u])) {
                string w = dict[u].back(); dict[u].pop_back();
                st.emplace(w.back() - 'a', w);
            } else {
                res.push_back(w);
                st. pop();
            }
        }
        res.pop_back();
        reverse(all(res));

        for (auto row: dict)
            if (not empty(row)) {
                is_eulerian = false;
            }

        if (not is_eulerian) {
            
            cout << "No way\n";
            continue;
        }
                
        print_vec(res);
    }

    return 0;
}
