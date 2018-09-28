#include <cmath>
#include <iostream>
using namespace std;

int main () {


    double knownX[] = { 1, 2 };

    double givenY[] = { 2, 3 };

    int n = sizeof (knownX) / sizeof (knownX[0]);


    double xBar, yBar;

    xBar = yBar = 0.0;
    for (int i = 0; i < n; i++) {
        xBar += knownX[i];
    }
    xBar /= n;

    for (int i = 0; i < n; i++) {
        yBar += log10 (givenY[i]);
    }
    yBar /= n;

    double slope;

    double numerator, denominator;

    numerator = denominator = 0.0;

    for (int i = 0; i < n; i++) {
        numerator += (knownX[i] - xBar) * (log10 (givenY[i]) - yBar);
        denominator += (knownX[i] - xBar) * (knownX[i] - xBar);
    }

    slope = numerator / denominator;

    double yIntercept = yBar - (slope * xBar);

    double R, A;

    R = pow (10.0, slope);
    A = pow (10.0, yIntercept);

    cout << "Slope is " << slope << " and Y int is " << yIntercept << endl;

    double intpart;
    double check = std::modf (slope, &intpart);

    std::cout << "Check is " << check << "  int part is " << intpart << endl;
    int input;

    while (true) {
        cin >> input;
        // double ans = (slope * input) + yIntercept;
        double ans = A * pow (R, input);
        cout << ans << endl;
    }
    return 0;
}