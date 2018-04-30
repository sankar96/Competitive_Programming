/****
 *
 * Description : http://codeforces.com/problemset/problem/236/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <iostream>
using namespace std;

int main () {
    string st;
    cin >> st;
    int map[26] = { 0 };
    int count = 0;
    int len = st.length ();
    for (int i = 0; i < len; i++) {
        if (map[st[i] - 'a'] != 0) {
        } else {
            map[st[i] - 'a']++;
            count++;
        }
    }
    if (count & 1) {
        cout << "IGNORE HIM!";
    } else {
        cout << "CHAT WITH HER!";
    }
    return 0;
}
