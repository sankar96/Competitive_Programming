#include <iostream>
#include <set>
#include <variant>
using namespace std;

int main () {
    // your code goes here

    set<int> p;
    p.insert (64);
    p.insert (1);
    p.insert (49);
    p.insert (2);

    for (auto& it : p) {
      //  cout << it << endl;
    }

    variant <double> v;

    cout << sizeof (v);
    return 0;
}