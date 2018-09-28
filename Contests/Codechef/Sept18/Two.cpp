/****
 *
 * Description : https://www.codechef.com/SEPT18B/problems/CHEFADV
 * Created by : Sankaranarayanan G
 * Date : 2018-09-08 01:19:49
 *
 ****/


#include <iostream>
using namespace std;


void print (int flag) {
    if (flag == 1) {
        cout << "Chefirnemo";
    } else
        cout << "Pofik";
    cout << endl;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        if (n == 1 && m == 1) {
            print (1);
            continue;
        }

        n--;
        m--;

        int rem1 = n % x;
        int rem2 = m % y;

        if (n == 1 && m == 1) {
            print (1);
        }

        else if (rem1 > 1 || rem2 > 1) {
            print (2);
        }

        else if (rem1 != 1 && (rem2 == 1)) {
            if (((n - 1) >= 0) && ((n - 1) % x == 0)) {
                print (1);
            } else {
                print (2);
            }
        }

        else if ((rem1 == 1 && (rem2 != 1))) {
            if (((m - 1) >= 0) && ((m - 1) % y == 0)) {
                print (1);
            } else
                print (2);
        }

        else
            print (1);
    }
    return 0;
}