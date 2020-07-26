#include <iostream>
using namespace std;

class Base
{
public:
    Base(){;}
    virtual void f()
    {
        cout <<"Base:hello world" <<endl;
    }
    virtual void g()
    {
        cout <<"Base:g" <<endl;
    }

    virtual void h()
    {
        cout <<"Base:h" <<endl;
    }
};

class Derive: public Base
{
public:
    Derive(){;}
    void f()
    {
        cout <<"hello world" <<endl;
    }
    void g()
    {
        cout<<"Derive:g"<<endl;
    }
};

// 一个很有趣的问题。。。。为什么这里不需要用注释这中typedef...
//
//typedef void (*Fun)(Derive *ptr);
typedef void (*Fun)();

int main()
{
    Base *p = new Derive();
    long address = *(long*)p;
    cout<< address<< endl;
    Fun fun= (Fun)(*(long*)address);
    fun();
//    fun = (Fun)(*(((long*)address)+1));
//    fun();
//    fun = (Fun)(*(((long*)address)+2));
//    fun();
//    fun = (Fun)(*(((long*)address)+3));
    return 0;
}
