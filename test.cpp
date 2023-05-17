#include <iostream>
using namespace std;

class A {
   public:
    A() {
        cout << "create A" << endl;
    }
    ~A() {
        cout << "destory A" << endl;
    }
    virtual void show() {
        cout << "A" << endl;
    }
};

class B : public A {
   public:
    B() {
        cout << "create B" << endl;
    }
    ~B() {
        cout << "destory B" << endl;
    }

   private:
    void show() {
        cout << "B" << endl;
    }
};

int main() {
    A* t = new B;
    t->show();
    delete t;
    return 0;
}