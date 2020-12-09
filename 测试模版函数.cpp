#include <iostream>
using namespace std;


class Base{
public:
	Base(){}
	
	template <typename T>
	void fun(const T * p_t){
		cout << __func__ << __LINE__ <<endl;
		cout << *p_t;
	}
};

int main(){
	
	
	Base b;
	int a = 3;
	b.fun<int>(&a);
	
	string str = "ÄãºÃ";
	b.fun<string>(&str);
	
	return 0;
} 
