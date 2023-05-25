#include <array>
#include <iostream>
#include <memory>
#include <valarray>

using namespace std;

class A {
   public:
    void show() {
        cout << "hhhh" << endl;
    }
};

class B : protected A {
   public:
    void showw() {
        A::show();
        cout << "1" << endl;
    }
};

class Point {
   public:
    int x, y;
    explicit Point(int x = 0, int y = 0)
        : x(x), y(y) {}
};

void displayPoint(const Point& p) {
    cout << "(" << p.x << ","
         << p.y << ")" << endl;
}

template <typename T>
using arrtype = array<T, 12>;

int main() {
    /*B* b = new B;
    b->showw();
    delete b;
    valarray<int> arr(10,8);
    for(auto i:arr){
        cout << i << " ";
    }
    displayPoint(Point(1));
    Point p(1);
    arrtype<int> arr;
    for (auto& i : arr) {
        i = 8;
    }
    for (auto i : arr) {
        cout << i << " ";
    }*/
    unique_ptr<int> uptr = make_unique<int>(10);  // 离开 uptr 作用域的时候自动释放内存
    //unique_ptr<int> uptr1 = uptr;                 // 编译错误，std::unique_ptr<T> 是 move-only 的
    unique_ptr<int> uptr2 = move(uptr);
    cout << *uptr2;
}