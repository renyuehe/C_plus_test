#include <iostream>
using namespace std;

int fun1(){
	cout<<"fun1"<<endl;
	return 0;
}

// auto 指针需要 c++ 的特定版本？ 
auto fun2(){
	cout<<"fun2"<<endl;
	return fun1;
}

int main(){
	
	fun2();
	
	return 0;
}
