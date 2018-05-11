#include <iostream>
using namespace std;

class Sum {
    public:
    Sum (double x, double y) : x_ (x), y_ (y) {
    }

    void operator() (double* ans) {
        // return x_ + y_;
        *ans += x_ + y_;
    }

    private:
    double x_, y_;
};


int main () {
    Sum a (6.6, 7.8);
    double ans = 0.0;
    a (&ans);
    a (&ans);
    cout << ans << endl;
    return 0;
}