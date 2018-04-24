#include <iostream>
using namespace std;

int main () {
    int t;
    cin >> t;
    int sumx, sumy, sumz;
    sumx = sumy = sumz = 0;
    while (t--) {
        int x;
        cin >> x;
        sumx += x;
        cin >> x;
        sumy += x;
        cin >> x;
        sumz += x;
    }
    if (sumx == 0 && sumy == 0 && sumz == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}