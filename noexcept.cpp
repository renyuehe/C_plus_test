#include <iostream>
#include <hash_map>
#include <windows.h>
//#include <hash>
using namespace std;


void f() noexcept; // 函数 f() 不抛出异常 
void (*fp)() noexcept(false); // fp 指向可能抛出异常的函数
void g(void pfa() noexcept);  // g 接收指向不抛出异常的函数的指针


int main(){
	while(1){
		
		Sleep(1000);
	}
	return 0;
} 
