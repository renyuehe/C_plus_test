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
	A * a = new A;	// ��ߵ�ָ����ջ�ռ䣬�ұߵ� A �Ƕѿռ䡣 
	a->show(); 
	*a = {"Two",2};	//��ߵ�ָ����ջ�ռ䣬�ұߵ���ָ����ջ�ռ䡣 
	a->show();
//	delete a;
	return 0;
}
