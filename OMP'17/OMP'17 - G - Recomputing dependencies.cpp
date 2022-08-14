#include <bits/stdc++.h>
using namespace std;

void print(int n) {
    if (n == 0)
        cout << "-";
    else if (n == -1)
        cout << "#";
    else
        cout << n;
}

int main() {
    string s;
    getline(cin, s);
    while (s != "0") {
        vector<int> v;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i])
            {
            case '-':
                v.push_back(0);
                break;
            case '#':
                v.push_back(-1);
                break;
            case ' ':
                break;
            default:
                int j = i;
                while(isdigit(s[j]))
                    j++;
                v.push_back(stoi(s.substr(i, j)));
                i = j;
            }
        }

        for (int i = v.size()-1; i >= 0; i--) {
            if (v[i] > 0) {
                int j, k;
                for (j = i - 1, k = 0; k < v[i]; j--) {
                    if (v[j] >= 0)
                        k++;
                }
                v[i] = i - j - 1;
            }
        }

        print(v[0]);
        for (int i = 1; i < v.size(); i++) {
            cout << " ";
            print(v[i]);

        }
        cout << endl;


        getline(cin,s);
    }
}