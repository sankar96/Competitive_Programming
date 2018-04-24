#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int convertToInt (string line, int st, int end) {
    int ten = 1, ans = 0;
    while (end >= st) {
        ans += (line[end] - '0') * ten;
        ten *= 10;
        end--;
    }
    return ans;
}

int main () {
    // your code goes here
    int n;
    cin >> n;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<pair<int, int>, int> lines;

    std::pair<int, int> pushedObject;
    while (n--) {
        char op;
        int a, c, q;
        cin >> op;
        if (op == '?') {
            cin >> q;
            map<int, int> calc;
            if (calc[q] == -1) {
                cout << "0" << endl;
                continue;
            } else if (calc[q] != 0) {
                cout << calc[q] << endl;
                continue;
            }
            int count = 0;
            for (auto& it : lines) {

                // map <std::pair <int, int>, int> calculatedValues;
                int A1 = (it.first).first;
                int C1 = (it.first).second;
                /*
                                pair <int, int> tempPair = make_pair (A1, C1);
                                if (calculatedValues [tempPair] == -1) {
                                    continue;
                                }
                                else {

                                }
                                */
                int B1 = 1;
                int A2 = 0;
                int B2 = 1;
                int C2 = q;
                A1 = -A1;

                //     cout << A1 << " " << B1 << " " << C1 << "\n"
                //        << A2 << " " << B2 << " " << C2 << endl;
                int det = A1 * B2 - (A2 * B1);
                int numerator = (B2 * C1 - (B1 * C2));
                //   cout << numerator << " / " << det << endl;

                if (det == 0) {
                    continue;
                }
                if (numerator % det == 0) {
                    count += it.second;
                }
            }
            if (count == 0) {
                calc[q] = -1;
            } else
                calc[q] = count;
            cout << count << endl;
        } else {
            cin >> a >> c;
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
    return 0;
}