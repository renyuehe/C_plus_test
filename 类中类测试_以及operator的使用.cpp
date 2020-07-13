#include <conio.h>
#include <iostream>
 
using namespace std;

class A{
private:
	int a;

private:
	class B_test{
	private:
		int x;
	public:
		B_test(){
			x = 11;
		}

		B_test& operator+(){
			return *this;
		}

		void show(){
			cout<<"A==>B show0"<<endl;
		}	
	};

public: 
	typedef B_test B;
};

int main(){

	A::B b;
	int x;		
	+b;

	return 0;
}
