//
// Created by Sankaranarayanan G on 06/04/18.
//

#include <iostream>

using namespace std;

int main () {
    int n = 1000000;
    freopen ("input.txt", "w+", stdout);

    while (n--) {
        cout << rand () % 1000000 + 1 << endl;
    }
    return 0;
}