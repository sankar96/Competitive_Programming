/****
 *
 * Description : http://codeforces.com/problemset/problem/248/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    int l_closed, r_closed, l_opened, r_opened;
    l_closed = r_closed = l_opened = r_opened = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a == 0)
            l_closed++;
        else
            l_opened++;
        if (b == 0)
            r_closed++;
        else
            r_opened++;
    }
    cout << min (l_closed, l_opened) + min (r_closed, r_opened);
    return 0;
}
