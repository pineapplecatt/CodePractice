#include <iostream>
using namespace std;

int main() {
    auto plus = [] (int a, int b) -> decltype(a+b) { return a + b; };
    int c = plus(1, 2);
    cout << c << endl;
}