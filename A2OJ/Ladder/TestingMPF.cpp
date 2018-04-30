#include <gmp.h>
#include <gmpxx.h>
#include <iostream>
#include <mpfr.h>

#include <stack>
#include <vector>
using namespace std;


int main () {
    mpfr_t floats[100];
    for (int i = 0; i < 100; i++)
        mpfr_init (floats[i]);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string st;
        cin >> st;
        mpfr_set_str (floats[i], st.c_str (), 10, MPFR_RNDZ);
    }

    for (int i = 1; i < n; i++) {
        mpfr_add (floats[i], floats[i], floats[i - 1], MPFR_RNDZ);
    }
    cout << "Using MPFR" << endl;
    mpfr_out_str (stdout, 10, 10, floats[n - 1], MPFR_RNDZ);

    cout << "\nUsing Double" << endl;

    double ans = 1.33 + 1.22 - 1.33 - 1.22;
    cout << ans << endl;
    return 0;
}