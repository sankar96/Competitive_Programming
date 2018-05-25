#include <boost/variant/variant.hpp>
#include <iostream>
#include <mpfr.h>
#include <vector>

using namespace std;
using OperandVariant = boost::variant<std::string, MpfrObj, bool>;

class MpfrObj {
    public:
    mpfr_t mpfr;
    MpfrObj (string st) {
        mpfr_init (mpfr);
        mpfr_set_str (mpfr, st.c_str (), 10, MPFR_RNDZ);
    }
};
class Obj {
    public:
    OperandVariant op;
    int type;

    Obj (OperandVariant o, int t) {
        op = o;
        type = t;
    }
};


int main () {

    Obj a ("23", 1);

    Obj b (false, 3);

    mpfr_init (x);
    mpfr_set_str (x, "56", 10, MPFR_RNDZ);
    Obj c (x, 2);

    vector<Obj> vec;
    vec.push_back (a);
    vec.push_back (b);
    vec.push_back (c);

    for (auto& it : vec) {
        cout << it.type << endl;
    }
    return 0;
}