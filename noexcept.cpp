#include <iostream>
#include <hash_map>
#include <windows.h>
//#include <hash>
using namespace std;


void f() noexcept; // ���� f() ���׳��쳣 
void (*fp)() noexcept(false); // fp ָ������׳��쳣�ĺ���
void g(void pfa() noexcept);  // g ����ָ���׳��쳣�ĺ�����ָ��


int main(){
	while(1){
		
		Sleep(1000);
	}
	return 0;
} 
