#include "gmpfrxx.h"
#include <gmp.h>
#include <gmpxx.h>
#include <iostream>
#include <mpfr.h>

#include <stack>
#include <vector>

using namespace std;

int main () {

    mpz_t a, b, c;
    mpz_inits (a, b, c, NULL);
    mpfr_t floating_array[1000];

    stack<mpfr_class> elements;

    for (int i = 0; i < 1000; i++)
        mpfr_init (floating_array[i]);

    mpz_set_str (a, "56789", 10);
    mpz_set_str (b, "sankaras", 10);

    mpfr_class x ("45.6"), y ("57.67");
    elements.push (x);
    elements.push (y);

    mpz_add (c, a, b);

    cout << "\nThe exact result is:";

    char string_rep[1000];
    mpz_get_str (string_rep, 10, c);
    cout << string_rep;
    cout << endl;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string st;
        cin >> st;
        mpfr_set_str (floating_array[i], st.c_str (), 10, MPFR_RNDZ);
    }
    double t = 1.333;
    double u = 1.225;
    double v = 1.333;
    double w = 1.225;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now ();
    for (int i = 0; i < 1; i++)
        for (int i = 1; i < n; i++) {
            mpfr_add (floating_array[i], floating_array[i], floating_array[i - 1], MPFR_RNDZ);
            // y += t + u + v + w;
        }


    mpfr_out_str (stdout, 10, 6, floating_array[n - 1], MPFR_RNDZ);
    end = std::chrono::system_clock::now ();

    auto t1 = std::chrono::duration_cast<std::chrono::nanoseconds> (end - start);
    cout << t1.count () << endl;
    // 3454546546.353535*23242353456.54656*343536465.5757575
    //
    // float u = 0.0;
    // u += 1.333 + 1.225 - 1.333 - 1.225;
    // cout << t << endl;
    // cout << u << endl;

    cout << "Stack elements\n";
    while (!elements.empty ()) {
        mpfr_t n;
        mpfr_init (n);
        mpfr_set (n, elements.top ().get_mpfr_t (), MPFR_RNDZ);
        // n = elements.top ().get_mpf_t ();
        // mpfr_set_str (n, elements.top ().get_mpf_t (), 10, MPFR_RNDZ);
        mpfr_out_str (stdout, 10, 6, n, MPFR_RNDZ);
        cout << endl;
        // mpfr_out_str (stdout, 10, 6, (elements.top ()).get_mpf_t (), MPFR_RNDN);
        elements.pop ();
    }
    return 0;
}
