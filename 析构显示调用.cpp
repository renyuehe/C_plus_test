#include <iostream>
using namespace std;

class Base{
public:
	Base(){
		cout<<"base "<<endl;
	}
	~Base(){
		cout<<"base destroyed"<<endl;
	}
private:
	
}; 

int main()
{
	Base a;
	a.~Base();//��ʾ�������� 
 	return 0;
}
