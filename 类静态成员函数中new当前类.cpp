#include <iostream>
using namespace std;

class A{
public:
	A(){
		cout<<"A ����"<<endl;
	}
	~A(){
		cout<<"A ����"<<endl;
	}
	
	static A* fun(){
		A *a = new A;
	}
	
private:
};

int main()
{
	A::fun();
	
	
	return 0;
}
