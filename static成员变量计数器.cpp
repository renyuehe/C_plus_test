#include <iostream>
using namespace std;
 
class man{
public:
	man()
	{
		this->a++;
	}
	~man(){
		this->a--;
	}
	
	static void show(){
		cout<<"һ��"<<a<<"������"<<endl; 
	}
	static int a;
}; 
//static��ʼ���� ���������������ʼ�� 
int man::a = 0; 

int main()
{
	man m;
	man m2;
	man m3;
	
	man::show();
 	return 0;
}
