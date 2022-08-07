#include <bits/stdc++.h>
using namespace std;

#define NO 0

unordered_set<string> strings;

enum type { ASSIGN, PRINT };
class instr {
public:
    enum type type;
    char var;
    char value;
    instr(enum type _type, char _var, char _value) : type(_type), var(_var), value(_value) {}
};


void back(vector<instr> &t1, vector<instr> &t2, int i, int j, vector<char> &values, string s) {
    if (i >= t1.size() && j >= t2.size()) {
        if (!s.empty()) {
            strings.insert(s);
        }
        return;
    }

    // thread1
    if (i < t1.size()) {
        instr ins = t1[i];
        if (ins.type == ASSIGN) {
            int old = values[ins.var];
            values[ins.var] = ins.value;
            back(t1, t2, i+1, j, values, s);
            values[ins.var] = old;
        }
        else {
            back(t1, t2, i+1, j, values, s + string(1, values[ins.var]));
        }
    }

    // thread2
    if (j < t2.size()) {
        instr ins = t2[j];
        if (ins.type == ASSIGN) {
            int old = values[ins.var];
            values[ins.var] = ins.value;
            back(t1, t2, i, j+1, values, s);
            values[ins.var] = old;
        }
        else {
            back(t1, t2, i, j+1, values, s + string(1, values[ins.var]));
        }
    }


}

void solve() {
    vector<instr> thread1, thread2;
    string s;

    //thread1
    getline(cin, s);
    while(s != "#") {
        if (s.size() > 5) { // print
            thread1.push_back(instr(PRINT, s[s.size() - 1], NO));
        }
        else {
            thread1.push_back(instr(ASSIGN, s[0], s[s.size() - 1]));
        }

        getline(cin, s);
    }

    //thread2
    getline(cin, s);
    while(s != "#") {
        if (s.size() > 5) {
            thread2.push_back(instr(PRINT, s[s.size() - 1], NO));
        }
        else {
            thread2.push_back(instr(ASSIGN, s[0], s[s.size() - 1]));
        }

        getline(cin, s);
    }
    
    vector<char> values(256, '0');
    back(thread1, thread2, 0, 0, values, "");

    // inputs
    getline(cin, s);
    while(s != "#") {
        if (strings.find(s) != strings.end())
            cout << "YES\n";
        else
            cout << "NO\n";    

        getline(cin, s);
    }
}

int main() {
    int casos;
    cin >> casos;
    cin.ignore(); // saltar salto de línea porque en solve se usa getline
    while (casos--) {
        strings.clear(); // borrar soluciones anteriores
        solve();
        if (casos) // en el último caso no va un salto de línea
            cout << endl;
    }
}
