#include <windows.h>
#include <iostream>
using namespace std; 

union xxx{
	int a = 0x11223344;
	char c;
}a;
	
int main(){
	printf("%#x\n",a.c);/* ��ӡ 44 ��С����  ��ӡ 11 �Ǵ������ */ 
	return 0;
}
