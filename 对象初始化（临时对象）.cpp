#include <iostream>
using namespace std; 

class A{
public:
	void func(int n){
		cout<<"NULL fun"<<endl;
	}

	void func(char *c){
		cout<<"NULL fun"<<endl;
	}
};

int main(){
	
	A a;
	
	a.func(NULL);
	a.func('a');
	
    return 0;
}

