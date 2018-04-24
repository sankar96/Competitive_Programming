/****
 *
 * Description : http://codeforces.com/problemset/problem/260/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/


#include <iostream>

using namespace std;

int main () {
    int a, b, n;
    cin >> a >> b >> n;
    int rem = a;
    int ans[100001];
    int index = 0;
    ans[index++] = a;
    int j;
    for (int i = 0; i < n; i++) {
        for (j = 0; j <= 9; j++) {
            // rem = ans[index - 1] % 10;
            rem = ans[index - 1];
            rem = (rem * 10 + j) % b;
            if (rem == 0) {
                ans[index++] = j;
                break;
            }
        }
        if (j == 10) {
            ans[index++] = 0;
        }
    }
    if (rem != 0) {
        cout << "-1\n";
    } else {
        for (int j = 0; j < index; j++) {
            cout << ans[j];
        }
        cout << endl;
    }
    return 0;
}
