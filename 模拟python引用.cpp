#include <iostream>
#include <memory>
using namespace std;

int main(){
	
	auto a = make_shared<int>(5);
	auto b = a;
	a = make_shared<int>(6);
	cout << *b << endl;
	
	//查看这种特殊 变量的类型 类似于指针 
	//cout << typeid(b).name() << endl;
	
#if 0
	#对应的python代码 
	a = 5
	b = a
	a = 6
	print(b)
#endif

	return 0;
}


