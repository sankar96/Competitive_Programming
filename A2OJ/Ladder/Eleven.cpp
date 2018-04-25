/****
 *
 * Description : http://codeforces.com/problemset/problem/80/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <iostream>
using namespace std;

bool prime (int m) {
    for (int i = 2; i * i <= m; i++) {
        if (m % i == 0)
            return false;
    }
    return true;
}
bool isPrime (int n, int m) {
    for (int i = n + 1; i <= m; i++) {
        if (prime (i)) {
            if (i == m)
                return true;
            else
                return false;
        }
    }
    return false;
}
int main () {
    int n, m;
    cin >> n >> m;
    if (isPrime (n, m)) {
        cout << "YES";
    } else
        cout << "NO";
    return 0;
}
