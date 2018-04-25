/****
 *
 * Description : http://codeforces.com/problemset/problem/271/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <iostream>
using namespace std;

int main () {
    int year;
    cin >> year;
    while (true) {
        year = year + 1;
        int a = (year / 1000) % 10;
        int b = (year / 100) % 10;
        if (a == b)
            continue;
        int c = (year / 10) % 10;
        if (a == c || b == c)
            continue;
        int d = year % 10;
        if (a != d && b != d && c != d) {
            break;
        }
    }
    cout << year << endl;
    return 0;
}
