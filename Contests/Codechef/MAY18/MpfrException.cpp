#include <gmpfrxx.h>
#include <iostream>
#include <mpfr.h>
using namespace std;

mpfr_t sum () {
    mpfr_t x;
    mpfr_init (x);

    mpfr_set_str (x, "5.6", 10, MPFR_RNDZ);
    return x;
}

int main () {

    mpfr_t a;
    mpfr_init (a);

    mpfr_set_str (a, "sfdgdg", 10, MPFR_RNDZ);

    mpfr_out_str (stdout, 10, 10, a, MPFR_RNDZ);

    mpfr_class x ("dgddg");

    mpfr_out_str (stdout, 10, 10, x.get_mpfr_t (), MPFR_RNDZ);

    return 0;
}