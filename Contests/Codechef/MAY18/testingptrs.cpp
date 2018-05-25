#include <iostream>
#include <vector>
using namespace std;

class BigClass {
    std::vector<int> v;

    public:
    BigClass () {
        v.resize (100000);
    }
};

int main () {

    std::vector<BigClass*> vec;
    // BigClass *bg;
    vec.reserve (10000);
    for (int i = 0; i < 10000; i++) {
        BigClass* bg = new BigClass ();
        vec.push_back (bg);
    }
    return 0;
}