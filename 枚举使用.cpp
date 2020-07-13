#include <stdio.h> 
#include <iostream>
using namespace std;


void fun(){
	
	cout << "fun" << endl; 
	
} 

void *pfun(){
	cout << "pfun "<<endl;
}

int a = 10;

int main(){
	
	printf("fun_ptr p = %p\n",fun);
	printf("&fun_ptr d = %d\n",&fun);
	
	printf("pfun_ptr p = %p\n",pfun);
	printf("&pfun_ptr d = %d\n",&pfun);
	
	void (*p1)() = fun;
	void *(*p2)() = pfun;
	cout << p1 <<endl;
	cout << p2 <<endl;
	printf("p1 = %d\n",p1);
	printf("p2 = %d\n",p2);
	
	return 0;
} 
