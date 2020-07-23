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
		cout<<"一共"<<a<<"个对象"<<endl; 
	}
	static int a;
}; 
//static初始化： 类中声明，类外初始化 
int man::a = 0; 

int main()
{
	man m;
	man m2;
	man m3;
	
	man::show();
 	return 0;
}
