#include <iostream>

struct job {
    char name[40];
    double salary;
    int floor;
};

// template<>void Swap<job>(job&, job&);
template <typename T>
void Swap(T& a, T& b);

const int* f1(const int arr[], int n);
const int* f2(const int[], int n);
const int* f3(const int*, int);

int main() {
    using namespace std;
    int arr[3] = {1, 2, 3};

    const int* (*p1)(const int*, int n) = f1;
    auto p2 = f2;

    cout << "Using pointers to functions:" << endl;
    cout << "    Address     Value:" << endl;
    cout << (*p1)(arr, 3) << ":   " << *p1(arr, 3) << endl;
    cout << p2(arr, 3) << ":   " << *p2(arr, 3) << endl;

    const int* (*pa[3])(const int*, int) = {f1, f2, f3};
    auto pb = pa;
    cout << endl
         << "Using an array of pointers to functions:" << endl;
    cout << "    Address     Value" << endl;
    for (int i = 0; i < 3; i++) {
        cout << pa[i](arr, 3) << ":   " << *pa[i](arr, 3) << endl;
    }
    cout << "\nUsing a pointer to a pointer to a function:\n";
    cout << "    Address     Value\n";
    for (int i = 0; i < 3; i++) {
        cout << pb[i](arr, 3) << ":   " << *pb[i](arr, 3) << endl;
    }

    cout << "\nUsing pointers to an array of pointers:\n";
    cout << "    Address     Value" << endl;
    auto pc = &pa;
    cout << (*pc)[0](arr, 3) << ":   " << *(*pc)[0](arr, 3) << endl;

    const int* (*(*pd)[3])(const int*, int) = &pa;

    const int* pdb = (*pd)[1](arr, 3);
    cout << pdb << ":   " << *pdb << endl;

    cout << (*(*pd)[2])(arr, 3) << ":   " << *(*(*pd)[2])(arr, 3) << endl;

    return 0;
}

const int* f1(const int* ar, int n) {
    return ar;
}

const int* f2(const int ar[], int n) {
    return ar + 1;
}

const int* f3(const int ar[], int) {
    return ar + 2;
}

template <typename T>
void Swap(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;

    decltype(a + b) x = a + b;
}

template <typename T1, typename T2>
auto gt(T1 x, T2 y) -> decltype(x + y) {
    return x + y;
}
