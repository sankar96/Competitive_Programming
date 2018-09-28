#include <iostream>
using namespace std;


class Node {
    int data;
    Node* left;
    Node* right;
};

void print (int a[], int low, int high) {
    if (low > high)
        return;

    int mid = low + (high - low) / 2;


    print (a, low, mid - 1);
    cout << a[mid];

    print (a, mid + 1, high);
}


int main () {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    print (arr, 0, n - 1);

    Node* root;

    construct (root);
    return 0;
}