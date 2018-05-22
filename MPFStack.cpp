#include <gmpfrxx.h>
#include <iostream>
#include <stack>
using namespace std;

int main () {
    int n;
    cin >> n;
    stack<mpfr_class> values;
    mpfr_class x;
    while (n--) {
        string st;
        cin >> st;
        x.set_str (st, 10);
        values.push (x);
        
    }

    while (!values.empty ()) {
        mpfr_out_str (stdout, 10, 6, values.top ().get_mpfr_t (), MPFR_RNDZ);
        values.pop ();
    }


    return 0;
}   