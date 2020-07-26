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

typedef long long u32;//¸ù¾Ý²»Í¬µÄ±àÒëÆ÷À´¾ö¶¨µ½µ×Ê¹ÓÃ (32Î»)4×Ö½Ú (64Î»)8¸ö×Ö½Ú£¬À´È·¶¨µ½µ×Ê¹ÓÃ int £¬ long £¬ »¹ÊÇ long long 

int main()
{
    Base *p = new Derive;
    
    cout << sizeof(u32) <<endl;
    
    u32 address = *(u32*)p;//pÊÇ¶ÔÏóµÄÖ¸Õë  
    cout<< address << endl;//å¾—åˆ°è¿™ä¸ªå¯¹è±¡çš„åœ°å€ 

    Fun fun= (Fun)(*(u32*)address);
    fun();
    
    
    //ä¸ºä»€ä¹ˆè¿™ä¸‰ä¸ªä»£ç ä¼šå°±å¡æ­»äº†  æ‰§è¡Œä¸äº†å‘¢ï¼Ÿ 
    fun = (Fun)(*(((u32*)address)+1));
    fun();
    fun = (Fun)(*((u32*)address+2));
    fun();
    
    return 0;
}

