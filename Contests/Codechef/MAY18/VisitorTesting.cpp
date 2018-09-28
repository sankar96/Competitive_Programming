#include <boost/variant.hpp>
#include <deque>
#include <iostream>


typedef boost::variant<std::string, bool, int> VariantObject;

class Visitor : public boost::static_visitor<> {
    public:
    bool isMPFR = false;

    void operator() (std::string& t) {
        // m_outStream << "String " << t << std::endl;
    }

    void operator() (bool& t) {
        // m_outStream << "Bool " << (t ? "TRUE" : "FALSE") << std::endl;
    }

    void operator() (int& t) {
        //
    }

    std::string Print (VariantObject variant_object) {
        m_outStream.clear ();
        boost::apply_visitor (*this, variant_object);
        return m_outStream.str ();
    }

    protected:
    std::stringstream m_outStream;
};

int main () {
    std::deque<VariantObject> objects;

    for (int i = 0; i < 1000000; i++) {
        int random = rand () % 1000000 + 4534;
        VariantObject v;
        if (random % 2 == 0) {
            v = 2;
            objects.push_back (v);
        } else if (random % 2 == 1) {
            v = true;
            objects.push_back (v);
        } else {
            v = "sankar";
            objects.push_back (v);
        }
    }

    Visitor visitor;

    for (auto& it : objects) {

        VariantObject v = it;
        visitor.Print (v);
    }
}