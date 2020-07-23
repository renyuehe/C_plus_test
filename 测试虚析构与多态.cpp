/*
*	结论：普通 虚函数 会被覆盖， 虚析构则会被 " 叠加 " 
*/

#include<iostream>
using namespace std;
//基类
class ClxBase{
public:
    ClxBase() {};
#if 0
    //析构函数不是虚函数
    ~ClxBase() {
        cout << "基类析构" << endl;
    };
#else
	//析构函数是虚函数 
    virtual ~ClxBase() {
        cout << "基类虚析构" << endl;
    };
#endif
 
#if 0
 	void DoSomething() {
        cout << "Do something in class ClxBase!" << endl;
    };
#else
    virtual void DoSomething() {
        cout << "Do something in class ClxBase!" << endl;
    };
#endif
};
 
//派生类
class ClxDerived : public ClxBase{
public:
    ClxDerived() {};
    ~ClxDerived() {
        cout << "子类析构" << endl;
    };
 
    void DoSomething() {
        cout << "Do something in class ClxDerived!" << endl;
    }
};
  int main(){ 
      //有多态
      ClxBase *p =  new ClxDerived;

      p->DoSomething();
      delete p;
      return 0;
  } 

