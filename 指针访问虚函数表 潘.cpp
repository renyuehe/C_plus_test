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

typedef long long u32;//根据不同的编译器来决定到底使用 (32位)4字节 (64位)8个字节，来确定到底使用 int ， long ， 还是 long long 

int main()
{
    Base *p = new Derive;
    
    cout << sizeof(u32) <<endl;
    
    u32 address = *(u32*)p;//p是对象的指针  
    cout<< address << endl;//寰楀埌杩欎釜瀵硅薄鐨勫湴鍧� 

    Fun fun= (Fun)(*(u32*)address);
    fun();
    
    
    //涓轰粈涔堣繖涓変釜浠ｇ爜浼氬氨鍗℃浜�  鎵ц涓嶄簡鍛紵 
    fun = (Fun)(*(((u32*)address)+1));
    fun();
    fun = (Fun)(*((u32*)address+2));
    fun();
    
    return 0;
}

