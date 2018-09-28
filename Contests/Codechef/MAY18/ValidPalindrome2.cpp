#include <iostream>
using namespace std;


bool validPalindrome (string s) {
    int left, right;
    left = 0;
    right = s.length () - 1;
    bool used = false;
    while (left < right) {
        cout << s[left] << " " << s[right] << endl;
        if (s[left] != s[right]) {
            if (s[left + 1] == s[right] && !used) {
                used = true;
                left += 2;
                right--;
            } else if (s[right - 1] == s[left] && !used) {
                used = true;
                right -= 2;
                left++;
            } else
                return false;
        } else {
            left++;
            right--;
        }
    }
    return true;
}

int main () {
    while (1) {
        string st;
        cin >> st;
        if (validPalindrome (st))
            cout << "true";
        else
            cout << "false";
        cout << endl;
    }
    return 0;
}