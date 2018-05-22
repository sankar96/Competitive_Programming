#include <iostream>
#include <vector>
using namespace std;

class Sum {
    public:
    void operator() (vector<int> p) const {
        for (auto &it : p ){ 
            cout << it << endl;
        }
    }
};

int main () {

    vector <int> v;

    v.push_back (7);
    v.push_back (8);

    Sum (v);
    return 0;
}