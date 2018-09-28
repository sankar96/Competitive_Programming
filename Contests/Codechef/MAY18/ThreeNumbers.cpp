/****
 *
 * Description : ThreeNumbers.cpp
 * Created by : Sankaranarayanan G
 * Date : 2018-08-26 15:50:33
 *
 ****/

#include <iostream>
using namespace std;


int FindNumberWithoutArray_Efficient (int a[], int n) {
    int powerof2 = 1;
    int answer = 0;
    for (int j = 31; j >= 0; j--) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (a[i] & 1);
            a[i] = a[i] >> 1;
        }
        sum = sum % 3;
        // The same thing is done here as in convert method. there an array was used. Here we are
        // directly adding the value to the "answer".
        answer += (sum * powerof2);
        powerof2 *= 2;
    }
    return answer;
}


int convert (int bits[]) {

    // Dont get worked out by looking at this method. Just paper la, write how will you convert a
    // binary number to a decimal number.

    // Like 110 - 6
    //      101 - 5
    // Epdi panuva, adu dan idu

    int answer = 0;
    int powerof2 = 1;

    for (int i = 31; i >= 0; i--) {
        answer += bits[i] * powerof2;
        powerof2 *= 2;
    }
    return answer;
}

int FindNumberWithArray_EASY (int a[], int n) {
    int bits[32];
    for (int j = 31; j >= 0; j--) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (a[i] & 1);
            a[i] = a[i] >> 1;
        }
        bits[j] = sum % 3;
    }

    // Testing
    // If you want to, print the value of bits array, it holds the binary of the resultant.

    cout << "Bits array\n";
    for (int i = 0; i < 32; i++) {
        cout << bits[i] << " ";
    }
    cout << endl;

    // Now, we have to convert this bits array to a decimal number.

    return convert (bits);
}


int main () {
    int n;
    cin >> n;
    int a[n];
    int copy[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        copy[i] = a[i];
    }

    cout << "First Method\n";
    cout << FindNumberWithArray_EASY (a, n);

    cout << "\n\nSecond Method\n";

    cout << FindNumberWithoutArray_Efficient (copy, n);
    return 0;
}
