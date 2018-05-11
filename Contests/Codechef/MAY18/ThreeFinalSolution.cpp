/****
 *
 * Description : https://www.codechef.com/MAY18B/problems/MTYFRI
 * Created by : Sankaranarayanan G
 * Date : 2018-05-11 16:01:33
 *
 ****/

#include <iostream>
using namespace std;

int getMax (int eArr[], int n) {
    int ma = eArr[0], in = 0;
    for (int i = 1; i < n; i++) {
        if (eArr[i] > ma) {
            ma = eArr[i];
            in = i;
        }
    }
    return in;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int eSize, oSize;
        eSize = oSize = n / 2 + 1;
        int eArr[eSize + 1];
        int oArr[eSize + 1];
        int eIndex, oIndex;
        int sum = 0;
        eIndex = oIndex = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                cin >> eArr[eIndex];
                eIndex++;
            } else {
                cin >> oArr[oIndex];
                sum += oArr[oIndex];
                oIndex++;
            }
        }

        // sort (eArr, eArr + eIndex, greater<int> ());
        sort (oArr, oArr + oIndex);
        int swaps = k;
        int checkingIndex = 0;
        for (int i = 0; i < oIndex; i++) {
            if (swaps == 0)
                break;
            int maxE = getMax (eArr, eIndex);
            int cSum = sum - oArr[i] + eArr[maxE];
            if (cSum > sum) {
                int temp;
                temp = oArr[i];
                oArr[i] = eArr[maxE];
                eArr[maxE] = temp;
                sum = cSum;
                swaps--;
            }
        }

        long long int oddSum, evenSum;
        oddSum = evenSum = 0;
        for (int i = 0; i < eIndex; i++) {
            evenSum += eArr[i];
        }

        for (int i = 0; i < oIndex; i++) {
            oddSum += oArr[i];
        }
        if (oddSum > evenSum)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
