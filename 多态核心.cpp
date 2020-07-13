#include <iostream>
using namespace std;

class A{
public:
	// 被覆盖 且 virtual 即可实现多态 
	virtual void show(){	
		cout<<"基类方法"<<endl;
	}
};

class A_1:public A{
	void show(){
		cout<<"A_1 子类方法"<<endl;
	}
};

class A_2:public A{
	void show(){
		cout<<"A_2 子类方法"<<endl;
	}
};

void polymophic(A *base){
	base->show();
}

int main(){
	
	A_1 a1;
	A_2 a2;
	
	polymophic(&a1);
	polymophic(&a2);
	
	return 0;
}
