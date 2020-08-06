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

typedef int u32;
//typedef long u32;
typedef long long u64;//根据不同的编译器来决定到底使用 (32位)4字节 (64位)8个字节，来确定到底使用 int ， long ， 还是 long long 


//确认目标：函数指针 取 虚函数  typedef void (*Fun)();
//编译器决定了 指针的位数 , 要做到正确的转换  先测试 sizeof(void *)<<endl ，在选择 sizeof(long long) ，定义 typedef long long u64;
//对象指针 指向一个指针数组，这个指针数组的第一个元素存放的是虚函数表的首地址  : u64 address = ((u64*)p)[0]; 至于第二个元素，第三个，还需要研究 
//虚函数表的地址 又对应一个 指针数组，这个指针数组的元素依次对应 对应的虚函数  ：Fun fun= (Fun)(  ((u64*)address)[0] );
//	Fun fun= (Fun)(  ((u64*)address)[0] );
//    fun = (Fun)(  ((u64*)address)[1]  ) ;
//    fun = (Fun)(  ((u64*)address)[2]  );
int main()
{
	cout <<"编译器是 sizeof(void *)位的："<<sizeof(void *)<<endl; 
    cout <<"int:"<< sizeof(int) << endl;
    cout <<"long:"<< sizeof(long) << endl;
    cout <<"long long:"<< sizeof(long long) << endl;
    cout <<"choose:"<< sizeof(u64) << endl;
    cout <<endl;
	
    Base *p = new Derive;
#if 1
    u64 address = *(u64*)p;//p是对象的指针 ，  (u32*)p 是一个指针数组 ， *(u32 *)p 是指针数组的首指针 等价与 ((u32 *)p)[0]   
#else if
	u64 address = ((u64*)p)[0];	//等价与 u32 address = *(u32*)p;
#endif
//	u32 address = ((u32 *)p)[1];	//跑远了！
 
    cout << "虚函数表的首地址：" << address << endl;// address 虚函数表的首地址 

#if 0 
	//address 虚函数表的首地址，再进一步取 * 就能取出虚函数了 
	
    Fun fun= (Fun)(*(u64*)address);
    fun();
    
    fun = (Fun)(*(((u64*)address)+1));
    fun();
    fun = (Fun)(*((u64*)address+2));
    fun();
#else if
	//address 虚函数表的首地址，再进一步取 * 就能取出虚函数了 
	Fun fun= (Fun)(  ((u64*)address)[0] );
    fun();
    
    fun = (Fun)(  ((u64*)address)[1]  ) ;
    fun();
    fun = (Fun)(  ((u64*)address)[2]  );
    fun();	
#endif
    
    return 0;
}

