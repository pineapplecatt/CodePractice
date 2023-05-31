#include <array>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
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
    pair<int, double> p{1, 2.3};
    map<int, double> m{};
   /*  m.emplace(p);
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second;
    }
    cout << endl
         << m[1];
    m.insert({2, 2.3});
    cout << m.size(); */

    m[3] = 1.2;
    pair<map<int, double>::iterator, bool> e = m.emplace(4, 2.3);
    cout << e.first->first << " " << e.first->second;

    m.insert(map<int, double>::value_type(6, 7.4));
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second;
    }
    return 0;
}