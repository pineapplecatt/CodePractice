#include <iostream>
#include<cmath>
using namespace std;

void trans(int n){
    for (int i = 31; i >= 0; i--) {
        cout << (1 & (n >> i));
    }
    cout << endl;
}


int main(){
    int num = 1234543;
    trans(num);

    return 0;
}