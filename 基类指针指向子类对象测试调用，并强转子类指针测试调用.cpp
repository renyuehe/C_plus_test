#include <iostream>
using namespace std; 


class A{
public:
	void show(){
		cout<<" A show " <<endl;
	}
	void print(){
		cout<<" A print " <<endl;
	}
};

class B : public A{
public:
	void bShow(){
		cout<<" B bShow " <<endl;
	}
};

int main()
{
	A *a = new B;
	a->show();
//	a->bShow();//�����ָ��  ���ܵ���  ����������ĺ����� 
	((B *)a)->bShow();//�����ٰ� ���� ָ����ת������ָ��Ϳ��Ե����� 

    return 0;
}
