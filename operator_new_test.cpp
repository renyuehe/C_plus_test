#include <iostream>
using namespace std;


int main(){
	
	void* a = operator new(100);	//这个 operator 到底是干啥用的 
	
	cout<<"a = :"<<a<<endl;
	
	return 0;
}
