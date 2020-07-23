//异常处理
#include <iostream>
using namespace std;


int main(){
	try{
		//try 块中放置可能抛出异常的代码 -》 保护代码
		//new 空间太大，申请内存失败，就会抛出异常 
		char * p = new char[0xfffffffff];
	}
	catch(exception e){
		cout<<"new space fail"<<endl;//捕获异常，其中 exception 是系统异常 
//		cout<<"new space fail"<<e.what()<<endl;
	}
	
	return 0;
} 
