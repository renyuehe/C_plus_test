#include <iostream>
#include <memory>
using namespace std;

int main(){

	int *a = new int[100];
	cout << _msize(a);
	
	return 0;
}
