#include <iostream>
#include <mpfr.h>
#include <vector>

using namespace std;

class Sum {
    public:
    void operator() (vector<int> p) const {
        for (auto& it : p) {
            cout << it << endl;
        }
    }
};

int main () {

    vector<int> v;

    v.push_back (7);
    v.push_back (8);

    mpfr_t a, b;
    mpfr_init (a);
    mpfr_init (b);

    mpfr_set_str (a, "2.0", 10, MPFR_RNDZ);
    mpfr_set_str (b, "3.0", 10, MPFR_RNDZ);

    cout << "<\t" << mpfr_less_p (a, b) << endl;
    cout << ">\t" << mpfr_greater_p (a, b) << endl;
    cout << "=\t" << mpfr_equal_p (a, b) << endl;
    cout << "<=\t" << mpfr_lessequal_p (a, b) << endl;
    cout << ">=\t" << mpfr_greaterequal_p (a, b) << endl;


    // Sum (v);
    return 0;
}