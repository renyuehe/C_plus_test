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
}; 


int main()
{
	Base a;
	a.~Base();//��ʾ�������� 
	while(1){
		
	}
 	return 0;
}


