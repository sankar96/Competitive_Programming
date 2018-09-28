#include <iostream>
#include <vector>
using namespace std;

class Value {
    int v;

    public:
    Value (int x) : v (x) {
    }
};

struct INTORD {
    int x;
    Value* value;
};


enum class POS { PREFIX, SUFFIX };
struct STRORD {
    int x;
    POS p;
    std::string* st;
};


union Test {
    INTORD i;
    STRORD j;
};


int main () {


    std::vector<Test> v;

    for (int i = 0; i < 5; i++) {
        if (i & 1) {
            STRORD s;
            std::string* sample = new string[100];
            *sample += "sankar";
            *sample += (i + '0');
            s.st = sample;
            Test t;
            t.j = s;
            v.push_back (t);
        } else {
            INTORD s;
            Test t;
            t.i = s;
            v.push_back (t);
        }
    }


    for (int i = 0; i < 5; i++) {
        if (i & 1) {
            Test t = v[i];
            STRORD s = t.j;
            std::cout << *(s.st) << std::endl;
        }
    }
    return 0;
}