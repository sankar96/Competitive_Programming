#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

long min (long a, long b) {
    return a < b ? a : b;
}

long max (long a, long b) {
    return a > b ? a : b;
}
int findSuperior (const vector<int>& freq) {
    long length = accumulate (freq.cbegin (), freq.cend (), 0);
    long totalMax = (length - 1) / 2;
    long limitLevel = 0;
    long charsUpToLimitLevelCount;

    for (charsUpToLimitLevelCount = 0;
         charsUpToLimitLevelCount <= length - totalMax && limitLevel < freq.size (); limitLevel++) {
        charsUpToLimitLevelCount += freq[limitLevel];
    }
    long countAtLimit = totalMax + charsUpToLimitLevelCount - length;
    charsUpToLimitLevelCount -= freq[--limitLevel];

    long matchingCount = min (countAtLimit, max (charsUpToLimitLevelCount - 1, 0));
    return totalMax - (countAtLimit - matchingCount);
}


int main () {
    int t;
    cin >> t;
    while (t--) {
        vector<int> freq (26);
        int c = 0;
        while (c < 26) {
            cin >> freq[c];
            c++;
        }
        cout << findSuperior (freq) << endl;
    }
}