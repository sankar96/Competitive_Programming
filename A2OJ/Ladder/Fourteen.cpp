/****
 *
 * Description : http://codeforces.com/problemset/problem/144/A
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
    int minPos, maxPos, minVal, maxVal;
    minVal = INT_MAX;
    maxVal = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] <= minVal) {
            minVal = arr[i];
            minPos = i;
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxPos = i;
        }
    }
    int ans = (n - 1) - minPos + maxPos;
    if (minPos < maxPos) {
        cout << ans - 1;
    } else {
        cout << ans;
    }
    return 0;
}
