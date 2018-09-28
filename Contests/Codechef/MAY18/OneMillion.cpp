#include <iostream>
#include <mpfr.h>
#include <sstream>


using namespace std;


int main () {

    mpfr_t a, b;
    mpfr_init (a);
    mpfr_init (b);

    mpfr_set_str (a, "1", 10, MPFR_RNDA);
    mpfr_set_str (b, "4.253535", 10, MPFR_RNDA);

    mpfr_exp_t exp;
    char* str;

    mpfr_get_str (str, &exp, 10, 10, b, MPFR_RNDA);

    for (int i = 0; i < strlen (str); i++) {
        std::cout << str[i];
    }

    std::cout << std::endl;

    // mpfr_sprintf (str, "%.6R*f\n", MPFR_RNDA, b);

    // for (int i = 0; i < strlen (str); i++) {
    //     std::cout << str[i];
    // }
    return 0;
}