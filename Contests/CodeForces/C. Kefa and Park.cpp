/****
 *
 * Description : https://codeforces.com/problemset/problem/580/C
 * Created by : Sankaranarayanan G
 * Date : 2018-09-28 16:04:48
 *
 ****/

#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <variant>

struct Node {
    int n;
    int count;
};

int main () {
    int n, cats;

    std::cin >> n >> cats;

    int vertices[n + 1];
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        std::cin >> vertices[i];
    }

    std::unordered_map<int, std::unordered_set<int>> graph;

    for (int i = 0; i < n - 1; i++) {
        int m, n;
        std::cin >> m >> n;
        graph[m].insert (n);
        graph[n].insert (m);
    }

    std::stack<Node> dfs;
    Node node;
    node.n = 1;
    node.count = vertices[1];
    dfs.push (node);

    std::unordered_set<int> visited;
    while (!dfs.empty ()) {
        Node top = dfs.top ();
        dfs.pop ();

        // std::cout << top.n << " " << top.count << std::endl;
        if (top.count > cats)
            continue;

        if (graph[top.n].empty () && top.n != 1) {
            answer++;
        }
        visited.insert (top.n);
        int count = 0;
        for (auto& it : graph[top.n]) {
            if (visited.find (it) == visited.end ()) {
                count++;

                Node temp;
                temp.n = it;
                if (vertices[it])
                    temp.count = top.count + 1;
                else
                    temp.count = 0;
                dfs.push (temp);
            }
        }

        if (count == 0)
            answer++;
    }

    std::variant<int, std::string> a;
    a = std::string ("naai");
    std::cout << std::get<std::string> (a) << "\n";

    std::cout << answer;
    return 0;
}