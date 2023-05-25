#include <iostream>
using namespace std;
int main(int argc, char const* argv[]) {
    class base {
       public:
        virtual void vir_func() { cout << "Virtual func,class base" << endl; }
        void func() { cout << "normal func,class base" << endl; }
    };
    class A : public base {
       public:
        virtual void vir_func() { cout << "Virtual func,class A" << endl; }
        void func() { cout << "normal func,class A" << endl; }
    };
    class B : public base {
       public:
        virtual void vir_func() { cout << "Virtual func,class B" << endl; }
        void func() { cout << "normal func,class B" << endl; }
    };
    base* Base = new (base);
    base* a = new (A);
    base* b = new (B);
    Base->func();  // normal func,class base
    a->func();     // normal func,class base
    b->func();     // normal func,class base
    cout << "###############################" << endl;
    Base->vir_func();  // Virtual func,class base
    a->vir_func();     // Virtual func,class A
    b->vir_func();     // Virtual func,class B
    cout << "###############################" << endl;
    ((A*)b)->vir_func();  // Virtual func,class B
    ((A*)b)->func();      // normal func,class A
    return 0;
}
