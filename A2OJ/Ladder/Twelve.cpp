/****
 *
 * Description : http://codeforces.com/problemset/problem/61/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <iostream>
using namespace std;

int main () {
    string num1, num2;
    cin >> num1;
    cin >> num2;
    int len = num1.length ();
    for (int i = 0; i < len; i++) {
        if ((num1[i] - '0') ^ (num2[i] - '0')) {
            cout << "1";
        } else
            cout << "0";
    }
    return 0;
}
