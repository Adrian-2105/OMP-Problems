#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

typedef vector<int> vi;

#define pb(x) push_back(x)


void solve() {
    string line, nota;
    getline(cin, line);
    stringstream ss;
    ss << line;

    vi v;
    int a;
    while (ss >> nota) {
        if (nota == "do")
            a = 0;
        else if (nota == "re")
            a = 1;
        else if (nota == "mi")
            a = 2;
        else if (nota == "fa")
            a = 3;
        else if (nota == "sol")
            a = 4;
        else if (nota == "la")
            a = 5;
        else if (nota == "si")
            a = 6;
        v.pb(a);
    }

    if (v.size() == 1) {
        cout << "escala ascendente\n";
        return;
    }

    bool asc = false;

    if (v[1] - v[0] == 1 || (v[0] == 6 && v[1] == 0)) {
        asc = true;
    }
    else if (!(v[0] - v[1] == 1 || (v[1] == 6 && v[0] == 0))) {
        cout << "no hay escala\n";
        return;
    }

    if (asc) {
        for (int i = 2; i < v.size(); i++) {
            if (!(v[i] - v[i-1] == 1 || (v[i-1] == 6 && v[i] == 0))) {
                cout << "no hay escala\n";
                return;
            }
        }
        cout << "escala ascendente\n";
    }
    else {
        for (int i = 2; i < v.size(); i++) {
            if (!(v[i-1] - v[i] == 1 || (v[i] == 6 && v[i-1] == 0))) {
                cout << "no hay escala\n";
                return;
            }
        }
        cout << "escala descendente\n";
    }
}

int main() {
    int casos;
    cin >> casos;
    string filtro;
    getline(cin, filtro);
    while (casos--)
        solve();
}

