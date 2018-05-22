#include <boost/any.hpp>
#include <gmpfrxx.h>
#include <iostream>
#include <mpfr.h>
#include <vector>
using namespace std;

int main () {
    vector<boost::any> anyVec;

    int i;
    cin >> i;
    
    anyVec.push_back (boost::any_cast<int> (i));
    mpfr_t a;

    double v;
    cin >> v;
    anyVec.push_back (boost::any_cast<double> (v));

    mpfr_t m;
    mpfr_init (m);

    string s;
    cin >> s;
    mpfr_class x (s);
    anyVec.push_back (boost::any_cast<mpfr_class> (x));

    for (auto& it : anyVec) {
        cout << it.type ().name () << endl;
    }


    return 0;
}