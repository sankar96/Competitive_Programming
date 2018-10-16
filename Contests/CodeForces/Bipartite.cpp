#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;
const int MAX = 100;

bool isBipartite (int G[][MAX], int V) {
    queue<int> bfs;
    bfs.push (0);

    int xor_val = 0;

    unordered_set<int> color1;
    unordered_set<int> color2;

    color1.insert (0);
    while (bfs.empty ()) {
        int top = bfs.front ();
        bfs.pop ();

        xor_val ^= 1;
        for (int i = 0; i < V; i++) {
            if (i != top) {
                if (G[top][i] == 1) {
                    if (xor_val == 1) {
                        if (color1.find (i) != color1.end ()) {
                            return false;
                        }
                        color2.insert (i);

                    } else {
                        if (color2.find (i) != color2.end ()) {
                            return false;
                        }
                        color1.insert (i);
                    }
                    bfs.push (i);
                }
            }
        }
    }

    return true;
}

int main () {
    int t;
    cin >> t;
    int g[MAX][MAX];
    while (t--) {
        memset (g, 0, sizeof (g));
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> g[i][j];
            }
        }

        cout << isBipartite (g, n) << endl;
    }
    return 0;
}