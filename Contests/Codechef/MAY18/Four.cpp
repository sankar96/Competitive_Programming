/****
 *
 * Description : https://www.codechef.com/MAY18B/problems/DBFB
 * Created by : Sankaranarayanan G
 * Date : 2018-05-05 11:46:27
 *
 ****/

#include <iostream>
#define MOD 1000000007
using namespace std;

// For 30 points

int main () {
    int t;
    std::ios::sync_with_stdio (false);
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int A[m + 1], B[m + 1];
        for (int i = 0; i < m; i++)
            cin >> A[i];
        for (int i = 0; i < m; i++)
            cin >> B[i];
        long long int result = 0;
        long long int fib[max (2, n) + 1];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                fib[0] = A[i];
                fib[1] = B[j];
                for (int k = 2; k < n; k++) {
                    fib[k] = (fib[k - 1] + fib[k - 2]) % MOD;
                }
                result = (result + (fib[n - 1]) % MOD) % MOD;
                cout << result << " ";
            }
        }
        cout << endl;
        cout << result << endl;
    }
    return 0;
}
