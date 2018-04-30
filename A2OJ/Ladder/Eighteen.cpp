/****
 *
 * Description : http://codeforces.com/problemset/problem/155/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int maxV = arr[0];
    int minV = arr[0];
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxV) {
            maxV = arr[i];
            count++;
        } else if (arr[i] < minV) {
            minV = arr[i];
            count++;
        }
    }
    cout << count;
    return 0;
}
