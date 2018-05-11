#include <gmpfrxx.h>
#include <iostream>
#include <stack>
using namespace std;

int main () {
    int n;
    cin >> n;
    stack<mpfr_t*> values;
    mpfr_t q;
    mpfr_class x ("456.7");
    cout << sizeof (x);
    while (n--) {
        string st;
        cin >> st;
        mpfr_set_str (q, st.c_str (), 10, MPFR_RNDZ);
        values.push (&q);
    }

    mpfr_t a, b, c;
    mpfr_init (a);
    mpfr_init (b);
    mpfr_init (c);

    mpfr_set_str (a, "0.1", 10, MPFR_RNDZ);
    mpfr_set_str (b, "0.2", 10, MPFR_RNDZ);
    mpfr_add (c, a, b, MPFR_RNDZ);
    mpfr_out_str (stdout, 10, 6, c, MPFR_RNDZ);


    while (values.empty ()) {
        mpfr_out_str (stdout, 10, 6, *values.top (), MPFR_RNDZ);
        values.pop ();
    }
    return 0;
}