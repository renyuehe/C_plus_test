#include <iostream>
using namespace std;

int fun1(){
	cout<<"fun1"<<endl;
	return 0;
}

// auto ָ����Ҫ c++ ���ض��汾�� 
auto fun2(){
	cout<<"fun2"<<endl;
	return fun1;
}

int main(){
	
	fun2();
	
	return 0;
}
