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
	a.~Base();//显示调用析构 
	while(1){
		
	}
 	return 0;
}


