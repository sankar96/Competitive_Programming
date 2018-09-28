#include <iostream>
#include <vector>

struct X {
    int x;
};

class Xx {

    int x;

    public:
    Xx (int i) {
        x = i;
    }
};

int main () {

    std::vector<Xx> v;
    for (int i = 0; i < 1000000; i++) {
        Xx x (i);

        v.push_back (x);
    }
    return 0;
}