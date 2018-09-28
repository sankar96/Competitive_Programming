#include "TestingEnum.hpp"
using namespace std;

enum class type { ONE, TWO, THREE };


int main () {
    unordered_map<type, int, Enum::EnumClassHash> m;
    m[type::ONE] = 1;
    m[type::TWO] = 123;
    m[type::THREE] = 2421;

    cout << m[type::THREE];
    return 0;
}