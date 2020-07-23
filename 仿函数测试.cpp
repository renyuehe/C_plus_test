#include <iostream>
using namespace std;

#if 0	//类仿函数 
class fun{
public:
	void operator()(){
		cout<<"仿函数"<<endl;
	}
};
#else	//结构体仿函数 
struct fun{
	void operator()(){
		cout<<"仿函数"<<endl;
	}
};
#endif

int main(){
	
//	fun f;	//类对象 
	
	struct fun f;	//结构体对象 
	f();
	
	return 0;
} 
