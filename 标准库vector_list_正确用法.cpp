#include <iostream>
#include <list>
#include <Vector>

using namespace std;

class B{
public:
	B(){ name = "���"; }
	string name;
};

class A{
public:
	list<B*> BList;//�ȳ�ʼ�� list ,������ʱ��ʼ�� B 
}; 


int main(){
	
	A a;
	B* b1 = new B;
	B b2;
	
	a.BList.push_back(b1);
	cout << a.BList.back()->name;
	 
	return 0;
} 
