/****
 *
 * Description : https://www.codechef.com/MAY18B/problems/DBFB
 * Created by : Sankaranarayanan G
 * Date : 2018-05-11 10:59:28
 *
 ****/

#include <iostream>
#define MOD 1000000007
using namespace std;

// For 100 points
int calc (int n) {
    long long int f[n + 1];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < n; i++)
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    return f[n - 1];
}

int main () {
    int t;
    std::ios::sync_with_stdio (false);
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        long long int f[2];
        f[0] = calc (n);
        f[1] = calc (n - 1);
        long long int a_sum, b_sum;
        a_sum = b_sum = 0;
        int temp;
        for (int i = 0; i < m; i++) {
            cin >> temp;
            a_sum = (a_sum + temp) % MOD;
        }

        for (int i = 0; i < m; i++) {
            cin >> temp;
            b_sum = (b_sum + temp) % MOD;
        }
        long long int result = 0;
        if (n < 2) {
            result = (m * (a_sum % MOD)) % MOD;
        } else {
            result = (m * ((f[0] * b_sum + f[1] * a_sum) % MOD)) % MOD;
        }
        cout << result << endl;
    }
    return 0;
}
