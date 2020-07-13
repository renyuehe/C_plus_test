#include <iostream>
using namespace std;


int main(){
	
//	int * bunch = new int;
	int * bunch = new int[3];
	
	*bunch = 10;
	*(bunch+1) = 20;
	bunch[2] = 40;
	bunch[3] = 50;
	bunch[4] = 100;
	bunch[5] = 200;
	
	cout<<*bunch<<endl;
	cout<<*(bunch+1)<<endl;
	cout<<bunch[2]<<endl;
	cout<<bunch[3]<<endl;
	cout<<bunch[4]<<endl;
	cout<<bunch[5]<<endl;
	
	return 0;
}
