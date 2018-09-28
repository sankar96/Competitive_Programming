/****
 *
 * Description : https://www.codechef.com/SEPT18B/problems/MAGICHF
 * Created by : Sankaranarayanan G
 * Date : 2018-09-08 00:18:09
 *
 ****/

#include <iostream>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, x, s;
        cin >> n >> x >> s;

        int pos = x;
        while (s--) {
            int a, b;
            cin >> a >> b;

            if (a == pos) {
                pos = b;
            } else if (b == pos) {
                pos = a;
            }
        }

        cout << pos << endl;
    }
    return 0;
}
