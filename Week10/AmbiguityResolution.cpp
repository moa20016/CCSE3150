#include <iostream>
using namespace std;

struct Top {
    virtual load runMe() = 0;
}

class Left : public virtual Top {
    public:
        void runMe() override { cout << "runMe in LEFT" << endl;}
};

class Right : public virtual Top {
    public:
        void runMe() override { cout << "runMe in RIGHT" << endl;}
};

class Bottom : public virtual Left {
    public:
        void runMe() override { cout << "runMe in Bottom" << endl;}
        Bottom() {
            Right::runMe();
            Left::runMe();
        }
};

int main() [
    Bottom bottom;
    bottom.runMe();

    return 0;
]