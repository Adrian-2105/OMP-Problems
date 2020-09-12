#include <iostream>
using namespace std;

typedef long long int ll;

// Nonario
int a, b;
// Decimal
int A, B, C;

ll potencia(ll n, int p) {
    if (p == 0)
        return 1;
    ll x = n;
    for (int i = 1; i < p; i++)
        x *= n;
    return x;
}

ll nonario_a_decimal(ll n) {
    // Eliminamos la restricción del 5 prohibido
    string s = to_string(n);
    for (int i = 0; i < s.length(); i++)
        if (s[i] > '5')
            s[i]--;

    n = 0;
    int cont = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        n += (s[i] - '0') * potencia(9, cont);
        cont++;
    }

    return n;
}

string decimal_a_nonario(ll n) {
    string s;
    s.reserve(15);

    while (n >= 9) {
        s.insert(s.begin(), n % 9 + '0');
        n /= 9;
    }
    s.insert(s.begin(), n + '0');

    // Aplicamos la restricción del 5 prohibido
    for (int i = 0; i < s.length(); i++)
        if (s[i] >= '5')
            s[i]++;
    return s;
}

int main() {
    while (cin >> a >> b)
        cout << decimal_a_nonario(nonario_a_decimal(a) * nonario_a_decimal(b)) << endl;
}
