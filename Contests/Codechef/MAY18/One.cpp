/****
 *
 * Description
 * Created by : Sankaranarayanan G
 * Date : 2018-05-04 18:24:10
 *
 ****/

#include <iostream>
using namespace std;

int main () {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        sort (arr, arr + N);
        int gcd_ = arr[0];
        int removed = 0;
        for (int i = 1; i < N; i++) {
            int temp = __gcd (gcd_, arr[i]);
            if (temp != 1) {
                removed++;
            }
        }
        if (N - removed == 1) {
            cout << "-1" << endl;
        } else
            cout << removed << endl;
    }
    return 0;
}