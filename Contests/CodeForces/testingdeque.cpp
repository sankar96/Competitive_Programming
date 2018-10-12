#include <deque>

#include <iostream>

int main () {

    std::deque<int> d;
    try {
        int de = d.back ();
    }

    catch (const std::out_of_range& e) {
        std::cout << "exception";
    }


    return 0;
}