#include <iostream>
using namespace std;
 
class A{
public: 
	virtual void set(){
		cout<<"���� ����"<<endl;
	}
};
 
class B: public A{
public:
	void set(){
		cout<<"���� ���Ǹ��෽��"<<endl;
		
		A::set();
	}

};
 
int main(){

	B b;
	b.set();
	
 	return 0;
}
