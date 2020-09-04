#include <stdio.h>
#include <iostream>
using namespace std;


//总结：值是没有区别的，区别在于形式，编译时可能不通过 
void fun(){
	
} 

int main()
{
	cout<<fun<<endl;
	cout<<&fun<<endl;
	
	printf("fun 打印d: %d" , fun);
	printf("\n");
	printf("&fun 打印d: %d" , &fun);
	printf("\n");
	printf("fun 打印p: %p" , fun);
	printf("\n");
	printf("&fun 打印p: %p" , &fun);
	printf("\n");
	
	return 0;
}
