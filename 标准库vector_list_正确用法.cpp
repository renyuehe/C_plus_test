#include <iostream>
#include <list>
#include <Vector>

using namespace std;

class B{
public:
	B(){ name = "你好"; }
	string name;
};

class A{
public:
	list<B*> BList;//先初始化 list ,最后添加时初始化 B 
}; 


int main(){
	
	A a;
	B* b1 = new B;
	B b2;
	
	a.BList.push_back(b1);
	cout << a.BList.back()->name;
	 
	return 0;
} 
