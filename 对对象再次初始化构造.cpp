#include <iostream>
#include <stdio.h>
using namespace std;

class A{
public:
	A(string name = "one", int num = 1){
		cout<<"A construct"<<endl;
		this->name = name;
		this->num = num;
	}
	~A(){
		cout<<"A destroyed"<<endl;
	}
	void show(){
		cout<<name<<endl;
		cout<<num<<endl;
	}
private:
	string name;
	int num;
};

int main(){
	A * a = new A;	// 左边的指针是栈空间，右边的 A 是堆空间。 
	a->show(); 
	*a = {"Two",2};	//左边的指针是栈空间，右边的是指针是栈空间。 
	a->show();
//	delete a;
	return 0;
}
