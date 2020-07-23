#include <iostream>
using namespace std;

class Demo
{
public:
    Demo(int i = 0) {
        p = new int;
        *p = 0;
        cout << this << "---------normal----------" << endl;
    }
    Demo(const Demo &obj) {
        //分配自己的空间：深拷贝
        p = new int;
        //拷贝值
        *p = *(obj.p);
        cout << &obj << "---------copy----------" << this << endl;
    }
    Demo(Demo &&obj) { //
        //得到临时对象的堆
        p = obj.p;
        //临时对象不能回收堆
        obj.p = nullptr;
        cout << &obj << "---------move----------" << this << endl;
    }
    ~Demo(){
        if(p){ //阻止重复回收
            delete p;
        }
        cout << this << "---------destroy----------" << endl;
    }

private:
    int *p;
};

//调用哪个构造是看语法，不是逻辑！！！
//编译器只会检查语法！！！

Demo test()
{
    //局部对象，test调用则产生构造，返回则消失析构
    Demo a;
    Demo c = a;
    cout << "a : " << &a << endl;
    cout << "c : " << &c << endl;
    return a;    //a拷贝出返回值，test函数返回值，返回值没有对象名的临时用的对象
}

int main()
{
#if 0
    Demo b = test();
    cout << "b : " << &b << endl;
#endif
#if 1
    Demo d(1); //normal construction
#else
    Demo d = 1; // Demo(1) ---move--> d //因为1是int型，所以先隐式转换成 Demo(1)，再 移动构造
//    Demo d = Demo(1); 与 Demo d = 1;  等价
#endif
//    cout << "d : " << &d << endl;
//    return 0;
}
