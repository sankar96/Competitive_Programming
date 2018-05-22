#include <gmpfrxx.h>
using namespace std;

int main () {
    // Calendar *cal =
    mpfr_class x ("");
    mpfr_out_str (stdout, 10, 10, x.get_mpfr_t (), MPFR_RNDZ);

    return 0;
}
