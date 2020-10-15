#include <stdio.h>
#include <iostream>
#include <Vector>
#include <windows.h>
using namespace std;

class A{
	
public:
#if 1
	//为什么这里 无参构造  就会编译不过（不应该是重载吗） 
	A(int a){
		cout<<"A类无参构造"<<endl;
	} 
#endif  
	A(A * parent = nullptr){
		cout<<"-------构建对象树-------"<<endl;
		if(parent != nullptr){
			Sleep(300);
			//创建对象数列表 
		}
	}	

	~A(){
			cout<<"-------对象树析构--------"<<endl;
	}

};

class B:public A{
public:
	B(A * parent = nullptr):A(parent){
		cout<<"B类构造"<<endl;
	}
};

int main(){
	A a(10);
	
	B b(&a);
	

	return 0;
}

