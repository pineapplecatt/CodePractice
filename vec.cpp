#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

class ParseClass {
   public:
    ParseClass() {
        std::cout << "构造函数" << std::endl;
    }

    ParseClass(int x) {
        std::cout << "构造函数带参数 " << x << std::endl;
    }
};

class testDemo {
   public:
    testDemo(int num)
        : num(num) {
        std::cout << "调用构造函数" << endl;
    }
    testDemo(const testDemo& other)
        : num(other.num) {
        std::cout << "调用拷贝构造函数" << endl;
    }
    /* testDemo(testDemo&& other)
        : num(other.num) {
        std::cout << "调用移动构造函数" << endl;
    } */

   private:
    int num;
};

class student {
   public:
    student(string name, int id, int age)
        : name(name), id(id), age(age) {}
    const int& getid() const {
        return id;
    }
    void setname(const string name) {
        this->name = name;
    }
    string getname() const {
        return name;
    }
    void setage(int age) {
        this->age = age;
    }
    int getage() const {
        return age;
    }

   private:
    string name;
    int id;
    int age;
};
class cmp {
   public:
    bool operator()(const student& stua, const student& stub) {
        return stua.getid() < stub.getid();
    }
};

template <typename T>
struct plus : public binary_function<T, T, T> {
    T operator()(const T& x, const T& y) const { return x + y; }
};

struct myPlus {
    int operator()(const int& a, const int& b) const {
        return a + b;
    }
    /* data */
};

// 定义一个模板函数，用来打印容器的内容
template <class Container>
void PrintContainer(const Container& con) {  // 这里用到了迭代器来实现打印容器种的内容
    class Container::const_iterator it = con.begin();
    while (it != con.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

void test() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    cout << v1.size() << endl;
    cout << v1.capacity() << endl;
    PrintContainer(v1);
    v1.resize(10);
    PrintContainer(v1);
}

int main() {
    /* array<double, 10> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it = arr.rbegin();

    while (it != arr.rend()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
    arr.fill(3);
    for (auto x : arr) {
        cout << x << " ";
    } */

    /* cout << "emplace_back:" << endl;
    std::vector<testDemo> demo1;
    demo1.emplace_back(2);
    cout << "push_back:" << endl;
    std::vector<testDemo> demo2;
    demo2.push_back(2); */
    /* test(); */
    /*     pair<int, double> p{1, 2.3};
        map<int, double> m{};
        /*  m.emplace(p);
         for (auto it = m.begin(); it != m.end(); it++) {
             cout << it->first << " " << it->second;
         }
         cout << endl
              << m[1];
         m.insert({2, 2.3});
         cout << m.size(); */

    /* m[3] = 1.2;
    pair<map<int, double>::iterator, bool> e = m.emplace(4, 2.3);
    cout << e.first->first << " " << e.first->second;

    m.insert(map<int, double>::value_type(6, 7.4));
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second;
    }
    m.count(1);

    multimap<int, int> mm{}; */

    /*set<student, cmp> myset{ {"zhangsan",10,20},{"lisi",20,21},{"wangwu",15,19} };
    auto it = myset.begin();
    const_cast<student&>(*it).setname("xiaoming"); */

    /* vector<int> myvec{1, 2, 3, 4, 5,6,7,8};
    std::reverse_iterator<vector<int>::iterator> my_reiter(myvec.end());
    reverse_iterator<vector<int>::iterator> begin(myvec.begin());
    reverse_iterator<vector<int>::iterator> end(myvec.end());
    for (auto it = begin.base(); it != end.base();++it){
        cout << *it << " ";
    }

    int arr[]{1, 2, 3, 4};
    for (int* it = begin(arr); it != end(arr);++it){
        myvec.emplace_back(*it);
    }
    PrintContainer(myvec); */
    cout << std::plus<int>()(10, 5) << endl;
    /* my_reiter += 2;
cout << my_reiter[2];  */

    /* plus a;
    cout << plus()(1, 2) << endl;        // 1、通过产生临时对象调用重载运算符
    cout << a.operator()(1, 2) << endl;  // 2、通过对象显示调用重载运算符
    cout << a(1, 2) << endl;             // 3、通过对象类似函数调用 隐示地调用重载运算符 */
    return 0;
}