/****
 *
 * Description : http://codeforces.com/problemset/problem/281/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <iostream>
using namespace std;

int main () {
    string st;
    cin >> st;
    if (st[0] >= 97 && st[0] <= 122) {
        st[0] -= 32;
    }
    cout << st;
    return 0;
}