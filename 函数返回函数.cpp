#include <iostream>
using namespace std;

typedef int (*fun_ptr)();

int fun1();
fun_ptr fun2(); 


int fun1(){
	cout<<"fun1";
	return 0;
}

fun_ptr fun2(){
	cout<<"fun2";
	return fun1; 
}


int main(){
	
	fun2()();

	return 0;
}

