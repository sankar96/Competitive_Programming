/****
 *
 * Description : http://codeforces.com/problemset/problem/275/A
 * Created by : Sankaranarayanan G
 * Date : 2018-03-13 15:01:28
 *
 ****/

#include <iostream>
using namespace std;

int main () {
    int lights[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            lights[i][j] = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int temp;
            cin >> temp;
            if (temp & 1) {
                if (i - 1 >= 0)
                    lights[i - 1][j] ^= 1;
                if (i + 1 < 3)
                    lights[i + 1][j] ^= 1;
                if (j + 1 < 3)
                    lights[i][j + 1] ^= 1;
                if (j - 1 >= 0)
                    lights[i][j - 1] ^= 1;
                lights[i][j] ^= 1;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << lights[i][j];
        cout << endl;
    }
    return 0;
}
