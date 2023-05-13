//用1~5随机数生成1~7随机数

#include <iostream>
#include <random>
using namespace std;

//生成1~5随机数
int f1(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(1, 5);

    return distrib(gen);
}

//等概率01生成器，12为0,45为1
int f2(){
    int ans = 0;
    do{
        ans = f1();
    } while (ans == 3);
    return ans < 3 ? 0 : 1;
}

//等概率生成0~7随机数
int f3(){
    return (f2() << 2) + (f2() << 1) + f2();
}

//等概率生成0~6随机数
int f4(){
    int ans=0;
    do{
        ans = f3();
    } while (ans == 7);
    return ans;
}

//生成1~7随机数
int Random(){
    return f4() + 1;
}

int main(){
    cout << Random() << endl;
}
