//用 非等概率01随机数生成函数 生成 等概率01随机数

#include <iostream>
#include <random>
using namespace std;

//非等概率生成0、1
int f1(){}

//等概率生成0、1
int f2(){
    int temp = 0;
    do{
        temp = (f1() << 1) + f1();
    } while (temp == 0 || temp == 3);
    return (temp == 0) ? 0 : 1;
}