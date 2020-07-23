#include <iostream>
#include <windows.h>
using namespace std; 

class A{
public:
	string name;
	int age;
	
	A(){
		cout<<"A 构造"<<endl;
		this->name = "月河";
		this->age = 25;
	}
	~A(){
		cout<<"A 析构"<<endl;
	}
	
	//类中的静态函数 创造本类对象出来  
	static int test(){
		static A a;//单例对象 
		
		while(1){
			Sleep(1000);
			cout<<"exec 循环"<<endl;
		}
		return 10;
	}
};

int main(){

	A::test();

    return 0;
}
