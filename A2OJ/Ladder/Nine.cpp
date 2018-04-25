/****
 *
 * Description : http://codeforces.com/problemset/problem/110/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <iostream>
using namespace std;

bool lucky (int count) {
    while (count) {
        if (count % 10 != 4 && count % 10 != 7) {
            return false;
        }
        count /= 10;
    }
    return true;
}

int main () {
    string st;
    cin >> st;
    int count = 0;
    int len = st.length ();
    for (int i = 0; i < len; i++)
        if (st[i] == '4' || st[i] == '7') {
            count++;
        }
    if (count != 0 && lucky (count)) {
        cout << "YES\n";
    } else
        cout << "NO\n";
    return 0;
}
