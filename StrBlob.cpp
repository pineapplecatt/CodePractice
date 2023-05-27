#include "StrBlob.hpp"
#include <iostream>

int main() {
    const StrBlob csb{"hello", "world", "pezy"};
    StrBlob sb{"hello", "world", "Mooophy"};
    cout << csb.front() << " " << csb.back() << endl;
    sb.back() = "pezy";
    cout << sb.front() << " " << sb.back() << endl;
}