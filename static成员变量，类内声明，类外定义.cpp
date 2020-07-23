#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
 
class man{
public:
//	man():a)(11)	//不行
	man()
	{
	//		a = 11; 	//不行
	}
	
//	static int a = 10;	//不行
	static int a;
}; 
//static初始化： 类中声明，类外初始化 
int man::a = 11; 

int main()
{
	man m;
//	m.a = 11;		//不行
//	man::a = 11;	//不行
//	man.a = 11;	//不行
 return 0;
}

