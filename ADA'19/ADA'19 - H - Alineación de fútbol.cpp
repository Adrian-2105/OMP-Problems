#include <iostream>
#include <string.h>
using namespace std;

int F, C, D, n;
string s;
bool jugadores[50][3];
bool flag = false;

#define f 0
#define c 1
#define d 2

void backtracking(int Fr, int Cr, int Dr, int i) {
    if (Fr == 0 && Cr == 0 && Dr == 0)
        flag = true;
    if (i == n)
        return;
    if (Fr > 0 && jugadores[i][f] && !flag)
        backtracking(Fr - 1, Cr, Dr, i + 1);
    if (Cr > 0 && jugadores[i][c] && !flag)
        backtracking(Fr, Cr - 1, Dr, i + 1);
    if (Dr > 0 && jugadores[i][d] && !flag)
        backtracking(Fr, Cr, Dr - 1, i + 1);
    if (!flag)
        backtracking(Fr, Cr, Dr, i + 1);
}

void solve() {
    // Lectura de la entrada
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.length(); j++)
            if (s[j] == 'F')
                jugadores[i][f] = true;
            else if (s[j] == 'C')
                jugadores[i][c] = true;
            else if (s[j] == 'D')
                jugadores[i][d] = true;
    }

    // Resolución e impresión del resultado
    backtracking(F, C, D, 0);
    if (flag)
        cout << "SI\n";
    else
        cout << "NO\n";
}

int main() {
    cin >> F >> C >> D;
    while (F || C || D) {
        memset(jugadores, false, sizeof(jugadores));
        flag = false;
        solve();
        cin >> F >> C >> D;
    }
}
