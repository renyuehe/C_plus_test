#include <windows.h>
#include <iostream>
using namespace std; 
	
class A{
public:
	A():count(0){
		cout<<"A construct"<<endl;
		cout<<"count = "<<count<<endl<<endl;
	}
	~A(){
		cout<<"A destruct "<<endl<<"count = "<<this->count<<endl<<endl;
	}
private:
	int count;
}; 
	
int main(){
	
	
	while(1){
		A a;
		Sleep(1000);
	}

	return 0;
}
