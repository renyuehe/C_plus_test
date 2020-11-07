#include <string.h>
#include<iostream>
using namespace std;


class A{
public:
    A(){
        memset(this,0,sizeof(this));//会把虚函数表都至0，
    }   
    ~A(){}

};

int main(){
    A a; //报错:*** stack smashing detected ***: <unknown> terminated; Aborted (core dumped)
    //A * a = new A;//不报错，因为虽然虚函数置0了，但是也没有调用 析构函数
    return 0;
}
