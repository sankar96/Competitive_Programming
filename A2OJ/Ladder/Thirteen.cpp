/****
 *
 * Description : http://codeforces.com/problemset/problem/233/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    if (n & 1)
        cout << "-1";
    else {
        for (int i = 1; i <= n; i++) {
            if (i & 1)
                cout << i + 1 << " ";
            else
                cout << i - 1 << " ";
        }
    }
    return 0;
}
