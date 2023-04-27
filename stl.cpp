#include<iostream>
using namespace std;
char* returnValue();
 
int main()
{
    std::cout << returnValue() << endl;
    return 0;
}
 
char* returnValue()
{
    char str[]="wrewew";
    return str;
}