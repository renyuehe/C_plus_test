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
	void set(){
		cout<<"子类 覆盖父类方法"<<endl;
		
		A::set();
	}

};
 
int main(){

	B b;
	b.set();
	
 	return 0;
}
