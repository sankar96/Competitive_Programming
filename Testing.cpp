#include <iostream>
#include <unordered_set>
using namespace std;

class S {
    public:
    string st;
    int val;

    S (int v, string s) {
        st = s;
        val = v;
    }
};

struct EqualTo {
    bool operator() (const S& s1, const S& s2) const {
        return s1.st == s2.st && s1.val == s2.val;
    }
};

struct Hash {
    size_t operator() (const S& s) const {
        int sum = 0;
        string arg = (s.st);
        int leng = arg.length ();
        return leng;
        for (int i = 0; i < leng; i++)
            sum += arg[i];
        return sum;
    }
};

int main () {
    // your code goes here
    unordered_set<S, Hash, EqualTo> sett;
    S obj (1, "sankar");
    S obj1 (2, "asnkar");
    S obj2 (2, "raknas");
    //	sett.insert ("abc");
    //	sett.insert ("abc");
    sett.insert (obj);
    sett.insert (obj1);
    sett.insert (obj2);
    for (auto& it : sett)
        cout << it.st << endl;
    return 0;
}