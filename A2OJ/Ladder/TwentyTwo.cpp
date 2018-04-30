/****
 *
 * Description : http://codeforces.com/problemset/problem/141/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <iostream>
using namespace std;

bool check (string st1, string st2, string st3) {
    int map[26] = { 0 };
    for (int i = 0; i < st3.length (); i++) {
        map[st3[i] - 'A']++;
    }

    for (int i = 0; i < st1.length (); i++) {
        if (map[st1[i] - 'A'] == 0) {
            return false;
        }
        map[st1[i] - 'A']--;
    }

    for (int i = 0; i < st2.length (); i++) {
        if (map[st2[i] - 'A'] == 0)
            return false;
        map[st2[i] - 'A']--;
    }

    for (int i = 0; i < 26; i++) {
        if (map[i] != 0) {
            return false;
        }
    }
    return true;
}

int main () {
    string st1, st2, st3;
    cin >> st1;
    cin >> st2;
    cin >> st3;
    if (check (st1, st2, st3)) {
        cout << "YES";
    } else
        cout << "NO";
    return 0;
}
