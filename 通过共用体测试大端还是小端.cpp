#include <windows.h>
#include <iostream>
using namespace std; 

union xxx{
	int a = 0x11223344;
	char c;
}a;
	
int main(){
	printf("%#x\n",a.c);/* 打印 44 是小端序  打印 11 是大端序列 */ 
	return 0;
}
