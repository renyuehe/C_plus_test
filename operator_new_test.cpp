#include <iostream>
using namespace std;


int main(){
	
	void* a = operator new(100);	//��� operator �����Ǹ�ɶ�õ� 
	
	cout<<"a = :"<<a<<endl;
	
	return 0;
}
