#include <iostream>
using namespace std;

class A{
public:
	// ������ �� virtual ����ʵ�ֶ�̬ 
	virtual void show(){	
		cout<<"���෽��"<<endl;
	}
};

class A_1:public A{
	void show(){
		cout<<"A_1 ���෽��"<<endl;
	}
};

class A_2:public A{
	void show(){
		cout<<"A_2 ���෽��"<<endl;
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
