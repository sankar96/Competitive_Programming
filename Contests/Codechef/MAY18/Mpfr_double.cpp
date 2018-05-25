#include <chrono>
#include <ctime>
#include <iostream>
#include <mpfr.h>
#include <ratio>
#define ONEMILLION 1000000
using namespace std;

void mpfr_d () {
    mpfr_t a;
    mpfr_init (a);
    mpfr_t b;
    mpfr_init (b);
    mpfr_set_str (a, "0.5585648756", 0, MPFR_RNDZ);
    for (int i = 0; i < ONEMILLION; i++) {
        mpfr_set (a, b, MPFR_RNDZ);
    }
}

void mpfr_string () {
    mpfr_t a;
    mpfr_init (a);
    string st = "1234343.5585648756";

    for (int i = 0; i < ONEMILLION; i++) {
        mpfr_set_str (a, st.c_str (), 10, MPFR_RNDZ);
    }
}
int main () {
    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now ();
    // std::cout << "f(42) = " << fibonacci (42) << '\n';
    mpfr_d ();
    end = std::chrono::system_clock::now ();

    auto t1 = std::chrono::duration_cast<std::chrono::milliseconds> (end - start);

    cout << t1.count () << endl;
    start = std::chrono::system_clock::now ();
    // std::cout << "f(42) = " << fibonacci (42) << '\n';
    mpfr_string ();
    end = std::chrono::system_clock::now ();
    t1 = std::chrono::duration_cast<std::chrono::milliseconds> (end - start);
    cout << t1.count () << endl;
}