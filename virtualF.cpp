#include <iostream>
using namespace std;
int main(int argc, char const* argv[]) {
	class base {
	public:
		virtual void vir_func() { cout << "Virtual func,class base" << endl; }
		void func() { cout << "normal func,class base" << endl; }
	};
	class A :public base {
	public:
		virtual void vir_func() { cout << "Virtual func,class A" << endl; }
		void func() { cout << "normal func,class A" << endl; }
	};
	class B :public base {
	public:
		virtual void vir_func() { cout << "Virtual func,class B" << endl; }
		void func() { cout << "normal func,class B" << endl; }
	};
	base* Base = new(base);
	base* a = new(A);
	base* b = new(B);
	Base->func(); a->func(); b->func();
	cout << "###############################" << endl;
	Base->vir_func(); a->vir_func(); b->vir_func();
	cout << "###############################" << endl;
	((A*)b)->vir_func();
	((A*)b)->func();
	return 0;
}
