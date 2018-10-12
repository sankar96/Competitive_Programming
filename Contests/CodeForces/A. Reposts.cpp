/****
 *
 * Description : https://codeforces.com/problemset/problem/522/A
 * Created by : Sankaranarayanan G
 * Date : 2018-10-12 18:34:31
 *
 ****/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;


struct Node {
    string st;
    int height;
};

string convert (string st) {
    string answer;

    for (auto&it:st) {
        answer += toupper (it);
    }
    return answer;
}

int main () {
    int n;
    cin >> n;

    unordered_map<string, unordered_set<string> > graph;
    while (n--) {
        string st1, st2, st3;
        cin >> st1 >> st2 >> st3;
        graph[convert(st3)].insert (convert(st1));
    }

    Node root;
    root.st = convert ("Polycarp");
    root.height = 1;

    queue <Node> bfs;
    bfs.push (root);

    int answer;
    while (!bfs.empty()) {
        Node front = bfs.front();
        bfs.pop();
        answer = front.height;

        for (auto&it : graph[front.st]) {
            Node temp;
            temp.st = it;
            temp.height = front.height + 1;
            bfs.push (temp);
        }
    }

    cout << answer;
    return 0;
}