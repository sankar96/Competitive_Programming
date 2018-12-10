// deque::max_size
#include <deque>
#include <iostream>
#include <vector>

using namespace std::chrono;


int main () {
    unsigned int i;
    std::deque<int> mydeque;


    mydeque.resize (16777216);

    high_resolution_clock::time_point t1 = high_resolution_clock::now ();

    std::fill (mydeque.begin (), mydeque.end (), 0);

    high_resolution_clock::time_point t2 = high_resolution_clock::now ();

    auto duration = duration_cast<milliseconds> (t2 - t1).count ();
    std::cout << duration << std::endl;

    return 0;
}