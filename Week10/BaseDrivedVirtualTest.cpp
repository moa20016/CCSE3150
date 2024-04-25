#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base Constructor\n"; }
    virtual ~Base() { cout << "Base Destructor\n"; }
    virtual void doSomething() { cout << "Something by Base\n"; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived Constructor\n"; }
    ~Derived() { cout << "Derived Destructor\n"; }
    void doSomething() override { cout << "Something by Derived\n"; }
};

int main() {
    Base* b = new Derived();
    b->doSomething();
    delete b;
}
