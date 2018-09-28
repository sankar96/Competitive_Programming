#include <iostream>
using namespace std;


class Employee {
    public:
    virtual void raiseSalary () {
        cout << "IN base class\n";
    }
};

class Manager : public Employee {
    public:
    Manager () = default;
    void raiseSalary () {
        cout << "Raise for MANAGER  : 5 lakhs\n";
    }
};

class SDE : public Employee {
    public:
    SDE () = default;
    void raiseSalary () {
        cout << "Raise for SDE  : 5 lakhs\n";
    }
};

class QA : public Employee {
    public:
    QA () = default;
    void raiseSalary () {
        cout << "Raise for QA : 1 lakhs\n";
    }
};

void globalRaiseSalary (Employee* emp[], int n) {
    for (int i = 0; i < n; i++)
        emp[i]->raiseSalary ();
}

int main () {
    int n = 8;
    // no of employees;

    // creating an array of n employees
    Employee* employee[n];
    int d = 0;
    while (n--) {
        if (n % 2 == 0) {
            // create a manager object
            Manager m;
            employee[d] = &m;
        } else if (n % 2 == 1) {
            // create a SDE object
            SDE s;
            employee[d] = &s;
        } else {
            // create QA obj
            QA q;
            employee[d] = &q;
        }
        d++;
    }

    globalRaiseSalary (employee, d);
}