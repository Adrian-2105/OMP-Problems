#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll points;
    cin >> points;
    ll firstx, firsty;
    ll prevx, prevy;
    double area = 0;
    points--;
    cin >> firstx >> firsty;
    prevx = firstx; prevy = firsty;
    while(points--){
        ll auxx, auxy;
        cin >> auxx >> auxy;
        area += (prevx*auxy - prevy*auxx);
        prevx = auxx; prevy = auxy;
    }
    area += (prevx*firsty - prevy*firstx);
    area /= 2;
    //cerr << "area2D = " << area << endl;
    ll prof;
    cin >> prof;
    area *= prof;
    //cerr << "area = " << area << endl;
    double perc, consumed, added;
    cin >> perc >> consumed >> added;
    //cerr << "perc = " << perc << endl;
    double consumedPerc = consumed / area * 100;
    //cerr << "consumedPerc = " << consumedPerc << endl;
    if(consumedPerc > perc) cout << "Lack of water. ";
    perc = fmax(0.0, perc- consumedPerc);
    double addedPerc = added / area * 100;
    //cerr << "addedPerc: " << addedPerc << endl;
    if(perc + addedPerc > 100.0) cout << "Excess of water. ";
    perc = fmin(100.0, perc+addedPerc);
    //cerr << endl;
    cout << "Final percentage: " << (int)perc << "%" << endl;
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}