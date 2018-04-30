/****
 *
 * Description : http://codeforces.com/problemset/problem/133/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <iostream>
using namespace std;

int main () {
    string st;
    cin >> st;
    int len = st.length ();
    bool flag = false;
    for (int i = 0; i < len; i++) {
        if (st[i] == 'H' || st[i] == 'Q' || st[i] == '9') {
            flag = true;
            break;
        }
    }
    cout << (flag ? "YES" : "NO");
    return 0;
}
