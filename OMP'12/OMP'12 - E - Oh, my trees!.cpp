#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb(x) push_back(x)

// Clase auxiliar binary search tree
class bst {
public:
    int n;
    bst* left;
    bst* right;

    bst(int _n) {
        n = _n;
        left = nullptr, right = nullptr;
    }

    ~bst() {
        delete left;
        delete  right;
    }

    bst* add(int _n) {
        if (_n < n)
            if (!left) {
                left = new bst(_n);
                return left;
            }
            else
                return left->add(_n);

        else // (_n > n)
            if (!right) {
                right = new bst(_n);
                return right;
            }
            else
                return right->add(_n);
    }

    void print() {
        cout << n << ":";
        if (left)
            cout << left->n;
        cout << "-";
        if (right)
            cout << right->n;
        cout << endl;
    }
};

int h, n;
string line;

void solve() {
    // Lectura de la entrada
    cin >> h;
    getline(cin, line); // filtro de \n
    // Variable auxiliar para agilizar la impresión de los resultados
    vector<vector<pair<int,bst*>>> arbol;
    for (int i = 0; i < h; i++) {
        // Lectura de cada nivel
        vector<pair<int,bst*>> v;
        getline(cin, line);
        stringstream ss;
        ss << line;

        while (ss >> n)
            v.pb(mp(n, nullptr));
        // Almacenamos los datos en el árbol
        arbol.pb(v);
    }

#define raiz arbol[0][0].second

    raiz = new bst(arbol[0][0].first);
    for (int i = 0; i < arbol.size(); i++)
        for (int j = 0; j < arbol[i].size(); j++)
            arbol[i][j].second =  raiz->add(arbol[i][j].first);

    for (int i = 0; i < arbol.size(); i++)
        for (int j = 0; j < arbol[i].size(); j++)
            arbol[i][j].second->print();

    delete raiz;
}

int main() {
    int casos;
    cin >> casos;
    while (casos--)
        solve();
}
