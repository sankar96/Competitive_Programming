/****
 *
 * Description : https://codeforces.com/problemset/problem/455/A
 * Created by : Sankaranarayanan G
 * Date : 2018-10-10 10:47:33
 *
 ****/

#include <iostream>
#include <unordered_map>

using namespace std;

int main () {
    int n;
    cin >> n;

    unordered_map<int, int> count;
    int dp[n + 1];
    int a[n];
    for (int i = 2; i < n; i++) {
        cin >> a[i];
        count[a[i]]++;
    }

    dp[0] = a[0];
    dp[1] = a[1];

    for (int i = 2; i < n; i++) {
        dp[i] = max (dp[i-1], count[a[i]]*)
    }
    return 0;
}
