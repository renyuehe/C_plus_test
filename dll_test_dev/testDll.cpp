#include <iostream>
#include <Windows.h>
using namespace std;

int main(){
	//LoadLibrary
	//GetProcAddress
	//FreeLibrary
	
	HINSTANCE hand = LoadLibrary("dll.dll");
//	typedef (*p_add)(int, int);//为什么不写返回值也可以呢 
	typedef int(*p_add)(int, int); 
	p_add p = (p_add)GetProcAddress(hand,"add");//不同的函数指针都是不同的，这里必须要强转一下 
	cout<<p(3,6)<<endl;
	
	system("pause");
	
	return 0;
}
