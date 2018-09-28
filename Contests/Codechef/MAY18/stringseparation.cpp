#include <iostream>
using namespace std;


int ExtractNumber (string str, int st, int end) {
    int number = 0;

    int i = end, ten = 1;
    while (i >= st) {
        number += (str[i] - 48) * ten;
        ten *= 10;
        i--;
    }
    return number;
}


bool hasNumberPrefix (string st, int& number) {
    int i = 0;
    while (i < st.length ()) {
        if (!(st[i] >= 48 && st[i] <= 57)) {
            break;
        }
        i++;
    }
    if (i == 0)
        return false;
    number = ExtractNumber (st, 0, i - 1);
    return true;
}

bool hasNumberSuffix (string st, int& number) {
    int i = st.length () - 1;

    while (i >= 0) {
        if (!(st[i] >= 48 && st[i] <= 57)) {
            break;
        }
        i--;
    }

    if (i == st.length() - 1)
        return false;
    number = ExtractNumber (st, i + 1, st.length () - 1);
    return true;
}

int main () {
    string input;
    cin >> input;

    int number;
    if (hasNumberPrefix (input, number)) {
        cout << "Prefix\n";
        cout << number << endl;
    } else if (hasNumberSuffix (input, number)) {
        cout << "Suffix\n";
        cout << number << endl;

    } else {
        cout << "Nothing\n";
    }
    return 0;
}