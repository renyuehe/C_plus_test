#include <iostream>
using namespace std;

template <typename satallite = string>
class B {
public:
    B(){}
    ~B(){}
    void setStr(string && a){
        str = a;
        str += ":haha";
        cout<<"str = "<<str<<endl;
    }
private:
    string str;
};

//模版类中的参数也可以是模版
template <typename yuehe,typename aili = string>
class A {
public:
    A(){}
    ~A(){}
    yuehe yueheObj;
private:
    
};


typedef A<B<int>> Document;

int main(){

    Document doc;
    
    //doc.yueheObj.setStr(std::move(string("nihao")));
    doc.yueheObj.setStr(string("nihao"));//采用临时参数传入，就必须用&&来接受，如果要改变&&的构造方法，就必须要写移动构造

    system("pause");
    return 0;
}