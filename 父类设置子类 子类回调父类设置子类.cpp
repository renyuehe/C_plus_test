#include <iostream>
using namespace std;

class A{
public: 
	A(){

	} 	
	~A(){

	} 
	
	void set(){
		cout<<"父类 联系 子类"<<endl;
	}
 	
};
 
class B: public A{
public:
	B(A a){
		cout<<"子类中：";
		a.set();
	}

};
 
int main(){
 	A a; 
 	a.set();
 	
 	B b(a);
 	
 	return 0;
}
