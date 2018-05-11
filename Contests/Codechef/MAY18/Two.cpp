/****
 *
 * Description : https://www.codechef.com/MAY18B/problems/XORAGN
 * Created by : Sankaranarayanan G
 * Date : 2018-05-04 18:46:35
 *
 ****/

#include <iostream>
#include <vector>
using namespace std;

int main () {
    // For the 30 points

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int xor_v = 0;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            temp += temp;
            xor_v = xor_v ^ temp;
        }

        cout << xor_v << endl;
    }
    return 0;
}
