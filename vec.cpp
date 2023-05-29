#include <iostream>
#include <vector>
#include <set>

using namespace std;

int sum(int a,int b ){
    return a + b;
}

int swap(int a,int b){
    int temp=a;
    a=b;
    b = temp;
}

int main(){
    /* vector<int> vec{1, 2, 3, 4, 5, 6};
    vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); ++it) {
        (*it)++;
    }
    for(auto x:vec){
        cout << x << " ";
    } */

    int a=1,b=2;
    swap(a,b);
    cout<<a<<" "<<b;
    //cout << sum(a, b);
    return 0;
}