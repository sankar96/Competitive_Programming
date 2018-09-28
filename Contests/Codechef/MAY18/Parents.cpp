/****
 *
 * Description : Parents.cpp
 * Created by : Sankaranarayanan G
 * Date : 2018-08-26 15:45:27
 *
 ****/


#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace std;

int main () {
    cout << "Input the number of edges you are gonna enter\n";
    int n;
    cin >> n;

    unordered_map<string, vector<string>> family;

    unordered_set<string> copy_of_parents;

    while (n--) {
        string parent, children;
        cin >> parent;
        cin >> children;

        if (copy_of_parents.find (parent) != copy_of_parents.end ()) {
            copy_of_parents.erase (parent);
        } else {
            copy_of_parents.insert (parent);
        }

        vector<string> temp;

        if (family[parent].size () != 0) {
            temp = family[parent];
        }
        temp.push_back (children);

        family[parent] = temp;
    }

    string first_parent = *(copy_of_parents.begin ());
    stack<string> traversing_stack;
    traversing_stack.push (first_parent);

    while (!traversing_stack.empty ()) {
        string temp = traversing_stack.top ();
        traversing_stack.pop ();

        if (family[temp].empty ()) {
            continue;
        }
        cout << "\nChildren of " << temp << endl;
        for (auto& it : family[temp]) {
            cout << it << " ";
            traversing_stack.push (it);
        }
    }

    return 0;
}