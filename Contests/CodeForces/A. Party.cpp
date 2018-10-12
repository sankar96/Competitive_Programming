/****
 *
 * Description : https://codeforces.com/problemset/problem/115/A
 * Created by : Sankaranarayanan G
 * Date : 2018-10-12 17:31:04
 *
 ****/


#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;


struct Node {
    int height;
    int val;
};

int main () {
    int n;
    cin >> n;
    unordered_map<int, unordered_set<int>> graph;

    vector<int> parents;
    for (int i = 1; i <= n; i++) {
        int parent;
        cin >> parent;
        if (parent != -1) {
            graph[parent].insert (i);
        } else
            parents.push_back (i);
    }

    int max_val = INT_MIN;
    for (auto& it : parents) {
        queue<Node> bfs;
        Node node;
        node.height = 1;
        node.val = it;
        bfs.push (node);

        int height = 0;
        while (!bfs.empty ()) {
            Node front = bfs.front ();
            bfs.pop ();

            cout << node.val << " " << node.height << endl;
            height = front.height;
            for (auto& it : graph[front.val]) {
                Node temp;
                temp.val = it;
                temp.height = front.height + 1;
                bfs.push (temp);
            }
        }

        cout << height << endl;
        max_val = max (max_val, height);
    }

    cout << max_val;

    return 0;
}