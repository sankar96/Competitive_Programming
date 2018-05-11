/****
 *
 * Description
 * Created by : Sankaranarayanan G
 *
 ****/

#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n;
    freopen ("input.txt", "r", stdin);

    cin >> n;
    vector<int> arr (n);
    std::chrono::time_point<std::chrono::system_clock> start, end;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    start = std::chrono::system_clock::now ();
    long long int sum = 0;
    // for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // cout << arr[i];
        sum += arr[j];
    }
    //}
    end = std::chrono::system_clock::now ();
    auto t1 = std::chrono::duration_cast<std::chrono::nanoseconds> (end - start);
    cout << t1.count () << endl;
    return 0;
}
