#include <fstream>
#include <iostream>
#include <mpfr.h>
using namespace std;


enum class testing {

};

int main () {
    mpfr_t x;
    mpfr_init (x);

    mpfr_set_str (x, "6.75", 10, MPFR_RNDA);

    // std::ofstream file;
    // file.open ("bla.txt");
    FILE* file = fopen ("test.txt", "a");
    // mpfr_asprintf (&answer, "%.6R*f", x);

    mpfr_fprintf (file, "%.6R*f", MPFR_RNDA, x);
    // mpfr_printf ("%.6R*F", MPFR_RNDA, x);

    // cout << answer << endl;
    /*
    file << answer;
    file << std::endl;
    file << answer;
    file.close ();
    */
    return 0;
}