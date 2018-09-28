#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<string> split_string (string);

long max (long a, long b) {
    return a > b ? a : b;
}

void construct (long* segTree, long int* A, int n, int low, int high, int pos) {
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

void lazyUpdate (int pos, int low, int high, int i, int j, int value, long* SegTree, long* lazy) {
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

long updatedQuery (long* SegTree, long* lazy, int low, int high, int qlow, int qhigh, int pos) {
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
// Complete the arrayManipulation function below.
long arrayManipulation (int n, vector<vector<int>> queries) {

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
        SegTree[i] = INT_MIN;
    }
    construct (SegTree, A, size, 0, n - 1, 0);
    vector<vector<int>>::iterator row;
    vector<int>::iterator col;
    for (row = queries.begin (); row != queries.end (); row++) {
        int input[6];
        int d = 0;
        for (col = row->begin (); col != row->end (); col++) {
            input[d++] = *col;
        }
        lazyUpdate (0, 0, n - 1, input[0] - 1, input[1] - 1, input[2], SegTree, lazy);
    }
    return updatedQuery (SegTree, lazy, 0, n - 1, 0, n - 1, 0);
}

int main (int argc, char** argv) {
    freopen (argv[1], "r", stdin);
    // ofstream fout (getenv ("OUTPUT_PATH"));

    string nm_temp;
    getline (cin, nm_temp);

    vector<string> nm = split_string (nm_temp);

    int n = stoi (nm[0]);

    int m = stoi (nm[1]);

    vector<vector<int>> queries (m);
    for (int i = 0; i < m; i++) {
        queries[i].resize (3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore (numeric_limits<streamsize>::max (), '\n');
    }

    long result = arrayManipulation (n, queries);

    cout << result << endl;

    return 0;
}

vector<string> split_string (string input_string) {
    string::iterator new_end
    = unique (input_string.begin (), input_string.end (),
              [](const char& x, const char& y) { return x == y and x == ' '; });

    input_string.erase (new_end, input_string.end ());

    while (input_string[input_string.length () - 1] == ' ') {
        input_string.pop_back ();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find (delimiter);

    while (pos != string::npos) {
        splits.push_back (input_string.substr (i, pos - i));

        i = pos + 1;
        pos = input_string.find (delimiter, i);
    }

    splits.push_back (input_string.substr (i, min (pos, input_string.length ()) - i + 1));

    return splits;
}
