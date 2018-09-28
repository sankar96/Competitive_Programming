/****
 *
 * Description : https://codeforces.com/problemset/problem/919/B
 * Created by : Sankaranarayanan G
 * Date : 2018-09-21 16:02:52
 *
 ****/


#include <iostream>
using namespace std;

int sum (int n) {
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main () {
    int n;
    int t;
    cin >> n;
    int arr[10001];
    
    int x = 1;
    for (int i = 1; i <= 10000; i++) {
        if (i % 10 == 0) {
            x += 9;
        }
        arr[i] = (i + 1) * 9 + x;
        cout << arr[i] << endl;
    }

    // cout << arr[n] << endl;

    /*

    // cin >> t;
    // while (t--) {
    for (int i = 1; i < 150; i++) {
        // cin >> n;
        n = i;
        int answer = 10 - sum (n);

        int ten = 10;
        while (n) {
            answer += ten * (n % 10);
            n /= 10;
            ten *= 10;
        }
        cout << answer << endl;
    }
    */

    // }
    return 0;
}
