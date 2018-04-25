/****
 *
 * Description : http://codeforces.com/problemset/problem/266/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <iostream>
using namespace std;

int main () {
    string st;
    int n;
    cin >> n;
    cin >> st;
    int previous = 0;
    int removalCount = 0;
    for (int i = 1; i < n; i++) {
        if (st[i] != st[previous]) {
            previous = i;
        } else {
            removalCount++;
        }
    }
    cout << removalCount;
    return 0;
}
