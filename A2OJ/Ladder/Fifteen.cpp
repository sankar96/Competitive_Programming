/****
 *
 * Description : http://codeforces.com/problemset/problem/200/B
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <iostream>
using namespace std;

int main () {
    double n;
    cin >> n;
    double drinksPercent = 0.0;
    for (int i = 0; i < n; i++) {
        double percent;
        cin >> percent;
        drinksPercent += (percent / 100.0);
    }
    drinksPercent = (drinksPercent / n) * 100.0;
    printf ("%.12f", drinksPercent);
    return 0;
}
