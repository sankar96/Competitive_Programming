#include <iostream>

struct IgnoreEquals {
    bool operator() (int c1, int c2) const {

        std::cout << c1 << " " << c2 << std::endl;
        return std::tolower (c1) == std::tolower (c2);
    }
};

bool CaseIgnoreCompare (const std::string& str1, const std::string& str2) {
    return std::equal (str1.begin (), str1.end (), str2.begin (), IgnoreEquals ());
}


int main () {
    std::cout << std::boolalpha;

    std::cout << CaseIgnoreCompare ("", "true");
    return 0;
}