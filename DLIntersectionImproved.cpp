#include <iostream>
#include <map>

using namespace std;

/*
 * Complete the dynamicLineIntersection function below.
 */
void dynamicLineIntersection (int n) {
    /*
     * Write your code here.
     */

    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);
    long long int countArray[201000];
    map<pair<int, int>, int> lines;


    std::pair<int, int> pushedObject;
    map<int, int> calc;
    for (int i = 0; i < 200999; i++)
        countArray[i] = 0;
    while (n--) {
        char op;
        int a, c, q;
        cin >> op;
        if (op == '?') {
            cin >> q;
            if (calc[q] == -1) {
                cout << "0" << endl;
                continue;
            } else if (calc[q] != 0) {
                cout << calc[q] << endl;
                continue;
            }

            for (auto& it : lines) {
                int tA, tC;
                tA = it.first.first;
                tC = it.first.second;
                int inc = it.second;
                int y = 0;
                for (; y <= 100000; y++) {
                    if ((y - tC) % tA == 0) {
                        countArray[y] += inc;
                    }
                }
            }
            lines.clear ();
            cout << countArray[q] << endl;
            calc[q] = countArray[q] == 0 ? -1 : countArray[q];
        } else {
            calc.clear ();
            cin >> a >> c;
            if (a == 0)
                continue;

            if (op == '+') {
                pushedObject = make_pair (a, c);
                lines[pushedObject] = lines[pushedObject] + 1;

            } else if (op == '-') {
                pushedObject = make_pair (a, c);
                lines[pushedObject] = lines[pushedObject] - 1;
                if (lines[pushedObject] == 0)
                    lines.erase (pushedObject);
            }
        }
    }
}

int main () {
    int n;
    cin >> n;
    cin.ignore (numeric_limits<streamsize>::max (), '\n');

    dynamicLineIntersection (n);

    return 0;
}
