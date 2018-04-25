/****
 *
 * Description : http://codeforces.com/problemset/problem/59/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/


#include <iostream>
using namespace std;

void printString (string st, int flag) {
    int i = 0;
    while (st[i] != '\0') {
        if (st[i] >= 65 && st[i] <= 90) {
            if (flag == 1) {
                st[i] += 32;
            }
        } else {
            if (flag == 2)
                st[i] -= 32;
        }
        cout << st[i];
        i++;
    }
}
int main () {
    string st;
    cin >> st;
    int lower, upper;
    lower = upper = 0;
    int i = 0;
    while (st[i] != '\0') {
        if (st[i] >= 65 && st[i] <= 90)
            upper++;
        else
            lower++;
        i++;
    }
    if (lower >= upper)
        printString (st, 1);
    else
        printString (st, 2);
    return 0;
}