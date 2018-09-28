#include <deque>
#include <iostream>

#include <mpfr.h>
using namespace std;

int main () {
    // deque<deque <int> > d;

    // for (int i = 0; i < 3; i++) {
    //     deque<int> q;
    //     for (int j = 0; j < 3; j++) {
    //         q.push_back (i * j);
    //     }
    //     d.push_back (q);
    // }


    // for (auto& itr : d) {
    //     for (auto& itc : itr) {
    //         //  std::cout << itc << std::endl;
    //     }
    //     // cout << endl;
    // }

    mpfr_t a;
    mpfr_init (a);

    mpfr_t b;

    mpfr_init (b);

    mpfr_set_ui (a, 10, MPFR_RNDA);

    // mpfr_ui_div (b, 2, a, MPFR_RNDA);
    
    mpfr_div_2si (a,a, 2, MPFR_RNDA);


    // for (int i = 0; i < 1000000; i++) {
    //     mpfr_set_ui (a, i, MPFR_RNDA);

    mpfr_out_str (stdout, 10, 6, a, MPFR_RNDA);

    //     // std::cout << std::endl;
    // }
}