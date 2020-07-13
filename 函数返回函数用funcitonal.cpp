#include <funcitonal>   //没有这个包 ，需要下载 
#incldue <iostream>

int fun1(){
	cout<<"fun1"<endl;
	return 0;
}


functional<int()> fun2(){
	cout<<"fun2"<<endl;
	return fun1;
}

int main(){
	
	fun2();
	
	return 0;
}
