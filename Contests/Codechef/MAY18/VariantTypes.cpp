#include <boost/variant.hpp>
#include <iostream>
using namespace std;


struct NumberOrderedPair {
    int x_value;
};

struct StringOrderedPair {
    std::string actual_string_;
};

struct StringWithNumberOrderedPair {

    int x_value_;
    int number_value_;
    std::string actual_string_;
};

struct BooleanOrderedPair {
    bool boolean_value_;
};

using AutoFillVariant
= boost::variant<NumberOrderedPair, StringOrderedPair, StringWithNumberOrderedPair, BooleanOrderedPair>;

class Visitor : public boost::static_visitor<string> {
    public:
    static Visitor& GetInstance () {
        static Visitor visitor;
        return visitor;
    }


    string operator() (NumberOrderedPair& i) {
        return "NOP";
    }

    string operator() (StringOrderedPair& s) {
        return "SOP";
    }

    string operator() (StringWithNumberOrderedPair& s) {
        return "SOPN";
    }

    string operator() (BooleanOrderedPair& s) {
        return "BOOL";
    }

    string ApplyVisitor (AutoFillVariant fv) {
        return boost::apply_visitor (*this, fv);
    }
};

int main () {
    std::vector<AutoFillVariant> v;

    AutoFillVariant av;

    for (int i = 0; i < 10; i++) {
        switch (i % 4) {
        case 0: {
            NumberOrderedPair n;
            n.x_value = i;
            av = n;
            v.push_back (av);
            break;
        }
        case 1: {
            StringOrderedPair sop;
            sop.actual_string_ = "sankar";
            av = sop;
            v.push_back (av);
            break;
        }
        case 2: {
            StringWithNumberOrderedPair sopn;
            sopn.number_value_ = 123;
            av = sopn;
            v.push_back (av);
            break;
        }
        case 3: {
            BooleanOrderedPair bop;
            bop.boolean_value_ = false;
            av = bop;
            v.push_back (av);
            break;
        }
        }
    }


    Visitor vi;
    for (auto& it : v) {
        cout << vi.ApplyVisitor (it) << endl;
    }
}