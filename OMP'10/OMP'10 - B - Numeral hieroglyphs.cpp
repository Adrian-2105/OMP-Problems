#include <iostream>
#include <map>
using namespace std;

map<char,int> m;

long long pot10(int p) {
    if (!p)
        return 1;
    long long n = 10;
    for (int i = 1; i < p; i++) {
        n *= 10;
    }
    return n;
}

bool creciente(string &s) {
    for (int i = 1; i < s.length(); i++)
        if (m[s[i-1]] > m[s[i]])
            return false;
    return true;
}

bool decreciente(string &s) {
    for (int i = 1; i < s.length(); i++)
        if (m[s[i-1]] < m[s[i]])
            return false;
    return true;
}

bool nomas9(string &s) {
    int cont = 1;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i-1]) {
            cont++;
            if (cont > 9)
                return false;
        }
        else
            cont = 1;
    }
    return true;
}

bool check(string &s) {
    return (creciente(s) || decreciente(s)) && nomas9(s);
}

long long valor(string &s) {
    long long n = 0;
    for (char c : s)
        n += pot10(m[c]);
    return n;
}

int main() {
    // Rellenado del mapa con el orden de los caracteres
    m['B'] = 0, m['U'] = 1, m['S'] = 2, m['P'] = 3,
    m['F'] = 4, m['T'] = 5, m['M'] = 6;

    int casos;
    string s;
    cin >> casos;
    while (casos--) {
        cin >> s;

        if (check(s))
            cout << valor(s) << endl;
        else
            cout << "error\n";
    }
}
