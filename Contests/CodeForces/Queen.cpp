/****
 *
 * Description : https://www.spoj.com/problems/QUEEN/
 * Created by : Sankaranarayanan G
 * Date : 2018-10-17 01:00:57
 *
 ****/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;


bool check (int a, int b, int n, int m, vector<vector<char> >& board) {

    //cout << "Checking " << a << " " << b << endl;   
    
     if (a < 0 || a >= n)
        return false;
    if (b < 0 || b >= m)
        return false;

    if (board[a][b] == 'X')
        return false;
    return true;
}

int convertToKEY (int a, int b, int m) {
    return ((a) * m )+ b ;
}

struct Node {
    pair<int, int> pos;
    int dist;
};
int main () {
    int T;
    ios::sync_with_stdio (false);
    cin.tie (NULL);
    cin >> T;
    
    int minus = -1;
    int row[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
    int col[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<vector<char> > board;
        unordered_set <int> visited;
        int qi, qj;
        for (int i = 0; i < n; i++) {
            vector<char> row;
            string temp;
            cin >> temp;
            for (int j = 0; j < m; j++) {
                row.push_back (temp[j]);
                if (temp[j] == 'S') {
                    qi = i;
                    qj = j;
                }
            }
            board.push_back (row);
        }

        queue<Node> bfs;
        int answer = INT_MAX;

        Node start;
        start.dist = 0;
        start.pos = make_pair (qi, qj);


        bfs.push (start);

        while (!bfs.empty ()) {
            Node top = bfs.front ();
            bfs.pop ();

            visited.insert (convertToKEY (top.pos.first, top.pos.second, m));
            if (board[top.pos.first][top.pos.second] == 'F') {
                answer = min (answer, top.dist - 1);
                continue;
            }
            pair<int, int> top_pos = top.pos;
            for (int i = 0; i < 8; i++) {
                if (check (top_pos.first + row[i], top_pos.second + col[i], n, m, board) && visited.find (convertToKEY (top_pos.first + row[i], top_pos.second + col[i], m)) == visited.end()) {
                    //cout << "Inside\n";
                    Node temp;
                    temp.dist = top.dist + 1;
                    temp.pos = make_pair (top_pos.first + row[i], top_pos.second + col[i]);
                    bfs.push (temp);
                }
            }
        }

        cout << ((answer == INT_MAX) ? minus : answer) << endl;
    }
    return 0;
}