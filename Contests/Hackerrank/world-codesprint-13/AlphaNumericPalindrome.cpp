#include <iostream>
#include <string>
using namespace std;

bool checkIsAlphaNumeric (char c) {
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return true;
    return false;
}

bool checkForEquality (char a, char b) {
    if (a >= 65 && a <= 90)
        a += 32;
    if (b >= 65 && b <= 90)
        b += 32;
    return a == b;
}

bool isPalindrome (string s) {
    int left, right;
    left = 0;
    right = s.length () - 1;

    while (left < right) {
        // cout << s[left] << " : " << s[right] << endl;
        if (checkIsAlphaNumeric (s[left])) {
            if (checkIsAlphaNumeric (s[right])) {
                if (checkForEquality (s[left], s[right])) {
                    left++;
                    right--;
                } else
                    return false;
            } else {
                right--;
            }
        } else {
            left++;
        }
    }
    return true;
}


int main () {
    while (1) {
        string st;
        std::getline (std::cin, st);
        cout << (isPalindrome (st) ? "true" : "false");
        cout << endl;
    }
}