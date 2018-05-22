#include <gmp.h>
#include <gmpfrxx.h>
#include <gmpxx.h>
#include <iostream>
#include <vector>
using namespace std;
class MpfrOpbject {
    public:
    mpfr_t val;

    MpfrOpbject () {
        mpfr_init (val);
    }
};
vector<MpfrOpbject*> v;


void init () {
    v.reserve (1000000);

    for (int i = 0; i < 1000000; i++) {
        MpfrOpbject* o = new MpfrOpbject ();
        v.push_back (o);
    }
}

void value () {

    for (int i = 0; i < 1000000; i++) {
        MpfrOpbject* opr = v[i];
        mpfr_set_str (opr->val, "10", 10, MPFR_RNDZ);
    }
}

void print () {
    for (int i = 0; i < 10000; i++) {
        mpfr_out_str (stdout, 10, 10, v[i]->val, MPFR_RNDZ);
        cout << endl;
    }
}

int main () {

    init ();

    value ();
    // mpfr_out_str (stdout, 10, 10, x.get_mpfr_t (), MPFR_RNDZ);

    // print ();

    // x (v[1]);

    // cout << &x << endl;
    // mpfr_out_str (stdout, 10, 10, x.get_mpfr_t (), MPFR_RNDZ);

    return 0;
}