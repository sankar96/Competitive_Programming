#include <boost/variant.hpp>
#include <chrono>
#include <iomanip>
#include <iostream>

using namespace std;
using namespace chrono;


class Value {
    public:
    int v;

    Value (int x) : v (x) {
    }
};

struct INTORD {
    int x;
    Value* value;
};


enum class POS { PREFIX = 1, SUFFIX = 2 };

struct STRORD {
    int x;
    POS p;
    std::string st;
};

using FillSeriesVariant = boost::variant<INTORD, STRORD>;

using namespace std::chrono;


class Visitor : public boost::static_visitor<POS> {
    public:
    static Visitor& GetInstance () {
        static Visitor visitor;
        return visitor;
    }


    POS operator() (INTORD& i) {

        return POS::PREFIX;
    }

    POS operator() (STRORD& s) {
        return POS::SUFFIX;
    }

    POS ApplyVisitor (FillSeriesVariant fv) {
        return boost::apply_visitor (*this, fv);
    }
};

int main () {

    std::vector<FillSeriesVariant> v;
    FillSeriesVariant fs;
    STRORD str;
    INTORD itr;

    for (int i = 0; i < 1000000; i++) {
        if (i & 1) {
            str.x = i + 1;
            str.p = POS::PREFIX;
            str.st = "sankar";
            str.st += (i + '0');
            fs = str;
            v.push_back (fs);
        }

        else {
            itr.x = i + 1;
            itr.value = new Value (i + 324);
            fs = itr;
            v.push_back (fs);
        }
    }

    high_resolution_clock::time_point t1 = high_resolution_clock::now ();

    Visitor* vis = new Visitor ();

    POS p;
    for (auto& it : v) {
        switch (vis->ApplyVisitor (it)) {
        case POS::PREFIX: {
            p = POS::PREFIX;
            break;
        }
        case POS::SUFFIX: {
            p = POS::SUFFIX;
            break;
        }
        }
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now ();

    cout << "Time for visitor " << duration_cast<milliseconds> (t2 - t1).count () << endl;

    cout << static_cast<int> (p) << endl;

    high_resolution_clock::time_point t3 = high_resolution_clock::now ();

    int k;
    int i = 0;
    for (auto& it : v) {
        if (i & 1) {
            k = boost::get<STRORD> (it).x;

        } else {
            k = boost::get<INTORD> (it).x;
        }
        i++;
    }

    high_resolution_clock::time_point t4 = high_resolution_clock::now ();

    cout << "Time for casting " << duration_cast<milliseconds> (t4 - t3).count () << endl;

    cout << k << endl;

    return 0;
}