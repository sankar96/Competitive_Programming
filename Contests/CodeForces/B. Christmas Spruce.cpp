/****
 *
 * Description : https://codeforces.com/problemset/problem/913/B
 * Created by : Sankaranarayanan G
 * Date : 2018-10-12 13:49:41
 *
 ****/


#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main () {
    int n;
    cin >> n;

    bool answer = true;
    unordered_map<int, unordered_set<int> > graph;

    for (int i = 1; i < n; i++) {
        int index;
        cin >> index;
        graph[index].insert (i + 1);
    }

    queue<int> bfs;
    bfs.push (1);

    while (!bfs.empty ()) {
        int top = bfs.front ();
        bfs.pop ();

        int count = 0;

        if (graph[top].empty ()) {
            continue;
        }
        for (auto& it : graph[top]) {
            bfs.push (it);
            if (graph[it].empty ()) {
                count++;
            }
        }
        if (count < 3) {
            answer = false;
            break;
        }
    }

    cout << ((answer) ? "Yes" : "No");
    return 0;
}