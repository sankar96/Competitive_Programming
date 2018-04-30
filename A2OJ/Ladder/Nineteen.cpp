/****
 *
 * Description : http://codeforces.com/problemset/problem/116/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    int passengers = 0;
    int maxV = passengers;
    while (n--) {
        int in, out;
        cin >> in >> out;
        passengers = (passengers - in) + out;
        maxV = max (maxV, passengers);
    }
    cout << maxV;
    return 0;
}
