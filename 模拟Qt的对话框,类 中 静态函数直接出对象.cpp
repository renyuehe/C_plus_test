#include <iostream>
#include <windows.h>
using namespace std; 

class A{
public:
	string name;
	int age;
	
	A(){
		cout<<"A ����"<<endl;
		this->name = "�º�";
		this->age = 25;
	}
	~A(){
		cout<<"A ����"<<endl;
	}
	
	//���еľ�̬���� ���챾��������  
	static int test(){
		static A a;//�������� 
		
		while(1){
			Sleep(1000);
			cout<<"exec ѭ��"<<endl;
		}
		return 10;
	}
};

int main(){

	A::test();

    return 0;
}
