#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

// Arrays de movimientos del caballo
int a[] = {1, 1, -1, -1, 2, 2, -2, -2};
int b[] = {2, -2, 2, -2, 1, -1, 1, -1};

void solve() {
    int rows, cols, x, y, newX, newY;
    cin >> rows >> cols >> x >> y;

    // Matriz con el número mínimo de movimientos para llegar a cada casilla
    // -1 = no visitado
    int T[rows][cols];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            T[i][j] = -1;
    T[x][y] = 0;

    queue<pii> q;
    q.push(make_pair(x, y));

    // Búsqueda primero en anchura
    while (!q.empty()) {
        x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            newX = x + a[i], newY = y + b[i];
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && T[newX][newY] == -1) {
                q.push(make_pair(newX, newY));
                T[newX][newY] = T[x][y] + 1;
            }
        }
    }

    // Búsqueda del máximo
    int max = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (T[i][j] > max)
                max = T[i][j];

    cout << max << endl;
}

int main() {
    int casos;
    cin >> casos;
    while (casos--)
        solve();
}
