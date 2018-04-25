#include <gmp.h>
#include <gmpxx.h>
#include <iostream>
using namespace std;

int main () {
    mpz_t a, b, c;
    mpz_inits (a, b, c, NULL);

    mpz_set_str (a, "1234", 10);
    mpz_set_str (b, "-5678", 10);

    mpz_add (c, a, b);

    cout << "\nThe exact result is:";
    char* string_rep;
    mpz_get_str (string_rep, 10, c);
    // mpz_out_str (stdout, 10, c);
    cout << string_rep;
    cout << endl;

    mpz_abs (c, c);
    cout << "The absolute value result is:";
    mpz_out_str (stdout, 10, c);
    cout << endl;
    return 0;
}
