#include <iostream>
#include <mpfr.h>
using namespace std;

int main () {

    mpfr_t a, b, c;
    mpfr_init (a);
    mpfr_init (b);
    mpfr_init (c);

    mpfr_set_ui (a, 4, MPFR_RNDZ);
    mpfr_set_ui (b, 6, MPFR_RNDZ);

    mpfr_sub (a, a, b, MPFR_RNDZ);

    mpfr_out_str (stdout, 10, 10, a, MPFR_RNDZ);

    
    return 0;
}