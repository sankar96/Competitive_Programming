/****
 *
 * Description : http://codeforces.com/problemset/problem/263/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <cmath>
#include <iostream>
using namespace std;

int main () {
    int i, j;
    int temp;
    int posx, posy;
    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= 5; j++) {
            cin >> temp;
            if (temp == 1) {
                posx = i;
                posy = j;
            }
        }
    }
    cout << abs (posx - 3) + abs (posy - 3);
    return 0;
}
