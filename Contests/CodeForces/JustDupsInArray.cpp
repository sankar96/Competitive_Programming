/****
 *
 * Description : Normal dups in array
 * Created by : Sankaranarayanan G
 * Date : 2018-10-17 16:21:01
 *
 ****/

// Here u can do like u said, Sort the array, and again do a traversal of the array to compare the elements Which is not efficient at all.

// So here lets use a map (hash table)

// In the map, we store the count for each element.


#include <iostream>
#include <unordered_map>
using namespace std;

int main () {
    int n;
    unordered_map<int, int> table;

    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        table[arr[i]]++; // incrementing the frequency
    }

    for (int i = 0; i < n; i++) {
        if (table[arr[i]] == 1) {
            cout << arr[i] << endl; // only printing the elements that has occurred only once, the count = 1
        }
    }
    return 0;
}
