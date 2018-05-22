#include <boost/variant/variant.hpp>

#include <gmpfrxx.h>
#include <iostream>
#include <mpfr.h>
#include <vector>

using VariantObj = boost::variant<int, std::string, mpfr_class>;
struct CustomObj {
    VariantObj obj;
    int type;
};

class MyCustomVisitor : public boost::static_visitor<> {
    public:
    void operator() (CustomObj& ob) const {
        // std::cout << "String "  << ob.obj <<  std::endl;
        if (ob.type == 1) {
            std::cout << "str" << std::endl;
        } else {
            std::cout << "i" << std::endl;
        }
    }
};
MyCustomVisitor myCustomVisitor;


// boost::apply_visitor (myCustomVisitor, VariantObj);


int main () {

    std::vector<CustomObj> d;
    CustomObj a;
    a.obj = "asas";
    a.type = 1;
    d.push_back (a);
    CustomObj b;
    b.obj = 56;
    b.type = 2;
    d.push_back (b);

    /* for (auto& it : d) {
         std::cout << it.obj << std::endl;
     }*/


    std::for_each (d.begin (), d.end (), boost::apply_visitor (myCustomVisitor));
    return 0;
}