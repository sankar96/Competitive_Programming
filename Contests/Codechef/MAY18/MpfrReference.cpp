#include <boost/variant.hpp>
#include <iostream>
#include <mpfr.h>

class MpfrObject {
    public:
    mpfr_t mpfr;

    MpfrObject (mpfr_t t) {
        mpfr_swap (mpfr, t);
    }
};


std::string RemoveDoubleQuotes (const std::string& operand) {
    std::string result;
    if (operand[0] == '\"') {
        result = operand.substr (1, operand.length () - 2);
    } else {
        result = operand;
    }
    return result;
}

bool CheckForNumber (const std::string& str) {
    std::string number = RemoveDoubleQuotes (str);
    try {
        size_t idx = 0; // Refer std::stod documentation to understand this
        std::stod (number, &idx);
        if (number.size () != idx)
            return false;
    } catch (std::out_of_range& range_error) {
        return false;
    } catch (std::invalid_argument& invalid_error) {
        return false;
    }
    return true;
}



int main () {
    using VariantObject = boost::variant<MpfrObject*, int>;

    std::cout << CheckForNumber ("\"1\"");
}