/****
 *
 * Description : http://codeforces.com/problemset/problem/112/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <iostream>
using namespace std;

int returnAnswer (int a, int b) {
    if (a == b)
        return 0;
    if (a < b)
        return -1;
    return 1;
}
int main () {
    string st1, st2;
    cin >> st1 >> st2;
    int ans = 0;
    int len = st1.length ();
    for (int i = 0; i < len; i++) {
        if (st1[i] >= 65 && st1[i] <= 90) {
            st1[i] += 32;
        }
        if (st2[i] >= 65 && st2[i] <= 90) {
            st2[i] += 32;
        }
        if (st1[i] < st2[i]) {
            ans = -1;
            break;
        } else if (st1[i] > st2[i]) {
            ans = 1;
            break;
        }
    }
    cout << ans;
    return 0;
}
