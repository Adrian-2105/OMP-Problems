#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    vector<vector<int>> v(9, vector<int>(9,-1));
    for(int i = 0; i < 9; i+=2){
        int count =0;
        for(int j = 0; j <= i; j++){
            if(count == 0){
                int aux;
                cin >> aux;
                v[i][j] = aux;
                count++;
            }else{
                count = 0;
            }
        }
    }

    for(int i = 0; i < 7; i+=2){
        for(int j = 0; j <= i; j+=2){
            if(v[i][j] != -1){
                //cout << v[i][j] << " " << v[i+2][j] << " " << v[i+2][j+2] << endl;
                v[i+1][j] = (v[i][j] + v[i+2][j] - v[i+2][j+2])/2;
                v[i+1][j+1] = (v[i][j] - v[i+2][j] + v[i+2][j+2])/2;
                v[i+2][j+1] = (v[i][j] - v[i+2][j] - v[i+2][j+2])/2;
            }
        }
    }

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < i; j++) {
            cout << v[i][j] << " ";
        }
        cout << v[i][i];
        cout << endl;
    }

}

int main(){
    int casos;
    cin >> casos;
    while(casos--){
        solve();
    }
}