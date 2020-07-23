#include <iostream>
using namespace std; 


class A{
public:
	void show(){
		cout<<" A show " <<endl;
	}
	void print(){
		cout<<" A print " <<endl;
	}
};

class B : public A{
public:
	void bShow(){
		cout<<" B bShow " <<endl;
	}
};

int main()
{
	A *a = new B;
	a->show();
//	a->bShow();//基类的指针  不能调用  子类中扩充的函数的 
	((B *)a)->bShow();//可以再把 基类 指针再转成子类指针就可以调用了 

    return 0;
}
