#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <mpfr.h>
#include <sstream>
#include <string>

std::string PrunedValue (std::string value, bool isExp = false) {
    std::string result;
    int copyTillIndex = value.length () - 1;
    bool dot_seen = true;

    for (int i = value.length () - 1;; i--) {
        if (value[i] == '.') {
            copyTillIndex = i - 1;
            dot_seen = false;
            break;
        }

        if (value[i] != '0') {
            copyTillIndex = i;

            break;
        }
    }
    for (int i = 0; i <= copyTillIndex; i++) {
        result += value[i];
    }

    if (!dot_seen && isExp) {
        result += ".00";
    }

    return result;
}


std::string PruneExponentialValue (std::string value) {
    int i = 0;
    std::string result;

    std::string temp;

    for (; value[i] != 'E'; i++) {
        temp += value[i];
    }
    result += PrunedValue (temp, true);

    for (; value[i] != '\0'; i++) {
        result += value[i];
    }
    return result;
}

std::string dtos (unsigned long x) {
    std::stringstream s;
    s << x;
    return s.str ();
}


bool Check (mpfr_exp_t exponent, bool& exponent_is_high, bool& negative) {
    if (exponent > 15) {
        exponent_is_high = true;
        negative = false;
    }

    if (exponent <= -15) {
        negative = exponent_is_high = true;
    }
}

std::string GetDisplayStringForMpfrObject (mpfr_t& mpfr_operand_) {

    char converted_string[100];

    mpfr_exp_t exponent;

    mpfr_exp_t exp = mpfr_get_exp (mpfr_operand_);

    mpfr_get_str (converted_string, &exponent, 10, 15, mpfr_operand_, MPFR_RNDN);

    std::cout << "Exp " << exponent << std::endl;

    std::string result;

    bool exponent_is_high = false;

    bool isNegativeExponent;
    Check (exponent, exponent_is_high, isNegativeExponent);


    // Handling for cases of exponent being greater than 15 and lesser than -15
    if (exponent_is_high) {
        // exponent = (isNegativeExponent) ? exponent - 1 : exponent + 1;
        exponent--;

        std::string result;

        int index = 0;
        if (converted_string[index] == '-') {
            result += '-';
            index++;
        }
        result += converted_string[index++];
        result += '.';

        for (int i = index; converted_string[i] != '\0' && i <= 8; i++) {
            result += converted_string[i];
        }
        result += 'E';
        result += std::to_string (exponent);

        return PruneExponentialValue (result);
    }

    mpfr_t zero;
    mpfr_init (zero);

    mpfr_set_d (zero, 0.0, MPFR_RNDN);

    if (exponent <= 0) {
        int st_index = 0;
        int result_index = 0;
        if (converted_string[st_index] == '-') {
            result += '-';
            result_index++;
            st_index++;
        }
        result += '0';
        result_index++;
        int position_of_dot = result_index;
        result += '.';
        result_index++;
        // put 'exponent' zeros

        int count = abs (exponent);

        while (count--) {
            result += '0';
            result_index++;
        }
        for (int i = st_index; result_index <= (position_of_dot + 8) && converted_string[i] != '\0'; i++) {
            result += converted_string[i];
            result_index++;
        }
        return PrunedValue (result);
    }

    bool encountered_decimal = false;

    int decimal_places = 0;

    int starting_index = 0;

    int dot_position = 0;

    if (converted_string[0] == '-') {
        result += converted_string[0];
        starting_index++;
        exponent++; // done for negative numbers.
    }

    while (converted_string[starting_index] != '\0') {
        if (decimal_places == (std::min (15 - dot_position, 8)))
            break;

        if (starting_index == exponent) {
            result += '.';
            result += converted_string[starting_index++];
            dot_position = result.length () - 1;
            encountered_decimal = true;
            continue;
        }
        result += converted_string[starting_index];
        starting_index++;
        if (encountered_decimal) {
            decimal_places++;
        }
    }
    return PrunedValue (result);
}

int main () {
    while (1) {
        std::string input;
        std::cin >> input;
        mpfr_t a;
        mpfr_init (a);
        mpfr_set_str (a, input.c_str (), 10, MPFR_RNDN);
        std::cout << GetDisplayStringForMpfrObject (a) << std::endl;
    }
    return 0;
}
