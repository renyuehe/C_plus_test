#include <iostream>
using namespace std;

class A{
public: 
	A(){

	} 	
	~A(){

	} 
	
	void set(){
		cout<<"���� ��ϵ ����"<<endl;
	}
 	
};
 
class B: public A{
public:
	B(A a){
		cout<<"�����У�";
		a.set();
	}

};
 
int main(){
 	A a; 
 	a.set();
 	
 	B b(a);
 	
 	return 0;
}
