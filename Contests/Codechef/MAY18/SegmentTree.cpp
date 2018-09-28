#include <iostream>
#include <stdio.h>

using namespace std;
long max (long a, long b) {
    return a > b ? a : b;
} 

void construct (long segTree[], long int* A, int n, int low, int high, int pos) {
    if (low == high) {
        segTree[pos] = A[low];
        return;
    }
    int mid = (low + high) / 2;
    construct (segTree, A, n, low, mid, 2 * pos + 1);
    construct (segTree, A, n, mid + 1, high, 2 * pos + 2);
    segTree[pos] = max (segTree[2 * pos + 1], segTree[2 * pos + 2]);
}

void update (int pos, int low, int high, int i, int j, int value, long segTree[]) {
    if (low > high || low > j || high < i) {
        return;
    }

    if (low == high) {
        segTree[pos] += value;
        return;
    }

    int mid = (low + high) / 2;

    update (2 * pos + 1, low, mid, i, j, value, segTree);
    update (2 * pos + 2, mid + 1, high, i, j, value, segTree);
    segTree[pos] = max (segTree[2 * pos + 1], segTree[2 * pos + 2]);
}

void lazyUpdate (int pos, int low, int high, int i, int j, int value, long SegTree[], long lazy[]) {
    if (lazy[pos] != 0) {
        SegTree[pos] += lazy[pos];
        if (low != high) {

            lazy[pos * 2 + 1] += lazy[pos];
            lazy[pos * 2 + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    if (low > high || low > j || high < i) {
        return;
    }

    if (low >= i && high <= j) {
        SegTree[pos] += value;

        if (low != high) {
            lazy[pos * 2 + 1] += value;
            lazy[pos * 2 + 2] += value;
        }
        return;
    }

    int mid = (low + high) / 2;
    lazyUpdate (2 * pos + 1, low, mid, i, j, value, SegTree, lazy);
    lazyUpdate (2 * pos + 2, mid + 1, high, i, j, value, SegTree, lazy);

    SegTree[pos] = max (SegTree[2 * pos + 1], SegTree[2 * pos + 2]);
}

long updatedQuery (long SegTree[], long lazy[], int low, int high, int qlow, int qhigh, int pos) {
    if (lazy[pos] != 0) {
        SegTree[pos] += lazy[pos];
        if (low != high) {

            lazy[pos * 2 + 1] += lazy[pos];
            lazy[pos * 2 + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    if (low > high || low > qhigh || high < qlow) {
        return INT_MIN;
    }

    if (low >= qlow && high <= qhigh) {
        return SegTree[pos];
    }

    int mid = (low + high) / 2;

    return max (updatedQuery (SegTree, lazy, low, mid, qlow, qhigh, 2 * pos + 1),
                updatedQuery (SegTree, lazy, mid + 1, high, qlow, qhigh, 2 * pos + 2));
}
long query (long segTree[], int qlow, int qhigh, int low, int high, int pos) {
    if (qlow > high || qhigh < low)
        return INT_MIN;
    if (qlow <= low && qhigh >= high)
        return segTree[pos];
    int mid = (low + high) / 2;
    return max (query (segTree, qlow, qhigh, low, mid, 2 * pos + 1),
                query (segTree, qlow, qhigh, mid + 1, high, 2 * pos + 2));
}

int main (int argc, char **argv) {
    int t;

    int n, q;

    freopen (argv[1], "r", stdin);
    scanf ("%d%d", &n, &q);

    long int* A = (long int*)calloc (n, sizeof (long int));

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
    long* SegTree = (long*)malloc (size * sizeof (long));
    long* lazy = (long*)calloc (size, sizeof (long));
    for (int i = 0; i < size; i++) {
        SegTree[i] = LLONG_MIN;
    }
    construct (SegTree, A, size, 0, n - 1, 0);
    while (q--) {
        int a, b, k;
        scanf ("%d %d %d", &a, &b, &k);
        lazyUpdate (0, 0, n - 1, a - 1, b - 1, k, SegTree, lazy);
        // cout << query (SegTree, 0, n - 1, 0, n - 1, 0) << endl;
    }
    cout << updatedQuery (SegTree, lazy, 0, n - 1, 0, n - 1, 0) << endl;

    return 0;
}