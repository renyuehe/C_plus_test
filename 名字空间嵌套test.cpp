//名字空间嵌套
#include <iostream>
using namespace std;

namespace a{
	void run(){
		cout<<"a,run"<<endl;
	}
}

namespace b{
	void run(){
		cout<<"b,run"<<endl;
	}
}

//名字空间的嵌套 
namespace c{
	namespace d{
		void run(){
			cout<<"c,d, run"<<endl;
		}
	}
}

int main(){
	
	a::run();
	b::run();
	c::d::run();
	
	return 0;
} 
