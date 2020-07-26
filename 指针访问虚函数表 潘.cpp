#include <iostream>
using namespace std;

class Base
{
public:
    Base(){;}
private: 
    virtual void func1()
    {
        cout <<"Base:func1" <<endl;
    }

    virtual void func2()
    {
        cout <<"Base:func2" <<endl;
    }

    virtual void func3()
    {
        cout <<"Base:func3" <<endl;
    }
};

class Derive: public Base
{
public:
    Derive(){;}
private:
    void func1()
    {
        cout <<"Derive: func1" <<endl;
    }
    void func2()
    {
        cout <<"Derive: func2 "<<endl;
    }
};

typedef void (*Fun)();

typedef long long u32;//���ݲ�ͬ�ı���������������ʹ�� (32λ)4�ֽ� (64λ)8���ֽڣ���ȷ������ʹ�� int �� long �� ���� long long 

int main()
{
    Base *p = new Derive;
    
    cout << sizeof(u32) <<endl;
    
    u32 address = *(u32*)p;//p�Ƕ����ָ��  
    cout<< address << endl;//得到这个对象的地址 

    Fun fun= (Fun)(*(u32*)address);
    fun();
    
    
    //为什么这三个代码会就卡死了  执行不了呢？ 
    fun = (Fun)(*(((u32*)address)+1));
    fun();
    fun = (Fun)(*((u32*)address+2));
    fun();
    
    return 0;
}

