#include <iostream>
using namespace std;
 
class A{
public: 
	virtual void set(){
		cout<<"父类 方法"<<endl;
	}
};
 
class B: public A{
public:
#if 1
	void set(){
		cout<<"子类 覆盖父类方法"<<endl;	
	}
	
	void set2(){
		A::set();
	}
#endif

};
 
int main(){

//	A::set();	//很明显是错误的，类方法想要直接用，除非是static 

	B b;
#if 1
	b.set();
	b.set2();
#endif
	b.A::set();
 	return 0;
}
