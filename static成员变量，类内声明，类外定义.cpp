#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
 
class man{
public:
//	man():a)(11)	//����
	man()
	{
	//		a = 11; 	//����
	}
	
//	static int a = 10;	//����
	static int a;
}; 
//static��ʼ���� ���������������ʼ�� 
int man::a = 11; 

int main()
{
	man m;
//	m.a = 11;		//����
//	man::a = 11;	//����
//	man.a = 11;	//����
 return 0;
}

