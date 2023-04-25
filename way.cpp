/*
 *  2 --->--- 4 --->--- 6 --->--- 8
 *  |  \   /  |  \    / |  \    / |
 *  ^    X    ^     X   ^    X    ^
 *  |  /   \  |  /   \  |  /    \ |
 *  1 --->--- 3 --->--- 5 --->--- 7
 *
 * 1->2->3->4
 * 2->3->4
 * 3->4->5->6
 * 4->5->6
 * 5->6->7->8
 * 6->7->8
 * 7->8
 */
 
#include <iostream>
using namespace std;

int result=0;

int way(int n){
    if(n==1){
        return 1;
    }else if(n==2){
        return 1;
    }else if(n%2==0){
        return way(n - 3) + way(n - 2) + way(n - 1);
    } else {
        return way(n - 2) + way(n - 1);
    }
}

int main(){
    int n;
    cin>>n;
    cout << way(n) << endl;
    return 0;
}
