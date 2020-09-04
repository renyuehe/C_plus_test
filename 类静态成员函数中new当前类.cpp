#include <iostream>
using namespace std;

class A{
public:
	A(){
		cout<<"A ¹¹Ôì"<<endl;
	}
	~A(){
		cout<<"A Îö¹¹"<<endl;
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
