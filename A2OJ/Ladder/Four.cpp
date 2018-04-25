/****
 *
 * Description : http://codeforces.com/problemset/problem/32/B
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <iostream>
using namespace std;

int main () {
    string st;
    cin >> st;
    string ans = "";
    int len = st.length ();
    for (int i = 0; i < len; i++) {
        if (st[i] == '-') {
            if (st[i + 1] == '-') {
                ans += "2";
            } else if (st[i + 1] == '.') {
                ans += "1";
            }
            i++;
        } else if (st[i] == '.') {
            ans += "0";
        }
    }
    cout << ans << endl;
    return 0;
}
