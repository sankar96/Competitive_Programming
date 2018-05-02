/****
 *
 * Description : http://codeforces.com/problemset/problem/227/B
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 ****/


#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    int vasya[n + 5];
    int petya[n + 5];
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        vasya[temp] = i + 1;
        petya[temp] = n - i;
    }
    int m;
    unsigned long long int v, p;
    v = p = 0;
    cin >> m;
    while (m--) {
        cin >> temp;
        v += vasya[temp];
        p += petya[temp];
    }
    cout << v << " " << p;
    return 0;
}
