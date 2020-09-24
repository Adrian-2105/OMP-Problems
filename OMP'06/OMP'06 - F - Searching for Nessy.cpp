#include <iostream>
using namespace std;

int main() {
    int casos, w, h;
    cin >> casos;
    while (casos--) {
        cin >> w >> h;
        cout << ((w / 3 ? w : w + 1) / 3) * ((h / 3 ? h : h + 1) / 3) << endl;
    }
}
