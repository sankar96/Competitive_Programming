/****
 *
 * Description : http://codeforces.com/problemset/problem/228/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <iostream>
#include <map>
using namespace std;

int main () {
    map<int, int> colors;
    for (int i = 0; i < 4; i++) {
        int temp;
        cin >> temp;
        colors[temp] = 1;
    }
    cout << 4 - colors.size ();
    return 0;
}
