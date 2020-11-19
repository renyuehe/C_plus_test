#include <iostream> 
using namespace std;
  
class A{
public:
	static A& getInstance(){
		static A a;
		return a;
	}
	int getValue(){
		return a;
	}
private:
	A(){
		a = 10;
	}
	int a;
};
  	
int main(){
	A a = A::getInstance();
	cout<<a.getValue()<<endl;
	
	A b = A::getInstance();
	cout<<a.getValue()<<endl;;

	return 0;
}
