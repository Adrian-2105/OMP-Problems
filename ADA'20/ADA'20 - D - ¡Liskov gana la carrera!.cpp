#include <stdio.h>  
#include <deque>
#include <iostream>
#include <vector>


using namespace std;

typedef vector<int> vi;

#define pb(x) push_back(x)  


int d, distancia, nobs, aux, ind;
int sig;
vi v;

void salto() {
    cout << "S";
    while (d == v[ind])
        ind++;
    d++;
}

int main(){
    while (cin >> distancia >> nobs) {
        v.clear();
        ind = 0;
        d = 0;
        for (int i = 0; i < nobs; i++) {
            cin >> aux;
            v.pb(aux);
        }

        while (ind < nobs) {
            sig = v[ind];
            //cout << endl << "d=" << d << "  sig=" << sig << "   ";

            while (d+10 <= sig) {
                d += 10;
                printf("G");
            }
            while (d+4 <= sig) {
                d += 4;
                printf("T");
            }
            while (d+1 <= sig) {
                d += 1;
                printf("P");
            }
            salto();
        }

        while (d < distancia) {
            d += 10;
            printf("G");
        }

        cout << endl;
    }
}
