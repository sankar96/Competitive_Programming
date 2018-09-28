/****
 *
 * Created by : Sankaranarayanan G
 * Date : 2018-06-06 15:52:18
 *
 ****/
#include <iostream>

using namespace std;
void construct (int segTree[], int A[], int n, int low, int high, int pos) {
    if (low == high) {
        segTree[pos] = A[low];
        return;
    }
    int mid = (low + high) / 2;
    construct (segTree, A, n, low, mid, 2 * pos + 1);
    construct (segTree, A, n, mid + 1, high, 2 * pos + 2);
    segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
}
int query (int segTree[], int qlow, int qhigh, int low, int high, int pos) {
    if (qlow > high || qhigh < low)
        return INT_MAX;
    if (qlow <= low && qhigh >= high)
        return segTree[pos];
    int mid = (low + high) / 2;
    return query (segTree, qlow, qhigh, low, mid, 2 * pos + 1),
           query (segTree, qlow, qhigh, mid + 1, high, 2 * pos + 2);
}
int main () {
    int t;
    cin >> t;
    for (int l = 1; l <= t; l++) {
        int n, q;
        scanf ("%d%d", &n, &q);
        int A[n];
        for (int i = 0; i < n; i++)
            scanf ("%d", &A[i]);
        int size;
        if ((n & (n - 1)) == 0) {
            size = n * 2 - 1;
        } else {
            int k = n;
            size = 1;
            while (k) {
                size = size << 1;
                k = k >> 1;
            }
            size *= 2;
            size--;
        }
        //		cout << size << endl;
        int SegTree[size];
        for (int i = 0; i < size; i++)e
            SegTree[i] = INT_MAX;
        construct (SegTree, A, size, 0, n - 1, 0);
        cout << "Scenario #" << l << ": " << endl;
        while (q--) {
            int l, r;
            scanf ("%d %d", &l, &r);
            cout << query (SegTree, l - 1, r - 1, 0, n - 1, 0) << endl;
        }
    }
    return 0;
}
