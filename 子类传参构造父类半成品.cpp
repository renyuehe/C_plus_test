#include <stdio.h>
#include <iostream>
#include <Vector>
#include <windows.h>
using namespace std;

class A{
	
public:
#if 1
	//Ϊʲô���� �޲ι���  �ͻ���벻������Ӧ���������� 
	A(int a){
		cout<<"A���޲ι���"<<endl;
	} 
#endif  
	A(A * parent = nullptr){
		cout<<"-------����������-------"<<endl;
		if(parent != nullptr){
			Sleep(300);
			//�����������б� 
		}
	}	

	~A(){
			cout<<"-------����������--------"<<endl;
	}

};

class B:public A{
public:
	B(A * parent = nullptr):A(parent){
		cout<<"B�๹��"<<endl;
	}
};

int main(){
	A a(10);
	
	B b(&a);
	

	return 0;
}

