/****
 *
 * Description : http://codeforces.com/problemset/problem/266/B
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/


#include <iostream>
using namespace std;

int main () {
    int n, iterations;
    cin >> n >> iterations;
    string arr;
    cin >> arr;
    while (iterations--) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == 'B' && arr[i + 1] == 'G') {
                arr[i] = 'G';
                arr[i + 1] = 'B';
                i++;
            }
        }
    }
    cout << arr << endl;
    return 0;
}
