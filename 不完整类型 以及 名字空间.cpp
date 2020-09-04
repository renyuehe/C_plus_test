/*****************************************************************************************************/

#if 0
#include <iostream>
using namespace std;

namespace base{
	class A;
}

int main(){
	//名字空间里的东西，必须带上作用域才能访问 
	//A *a;
	base::A *a;
	return 0;
}
#endif

/*****************************************************************************************************/

#if 0
#include <iostream>
using namespace std;

class A;

int main(){
	
	A *a;
	return 0;
}
#endif

/*****************************************************************************************************/

#if 1
#include <iostream>
using namespace std;

namespace base1{
	class A;
}
namespace base1{
	class A{
		public:
			void show(){
				cout<<"yes"<<endl;
			}
	};
}
int main(){
	//类名 和 名字空间名 都要相同才能匹配 
	
	//两种赋值方式都可以 
	base1::A *a(new base1::A);
	//base1::A *a = new base1::A;
	a->show();
	return 0;
}

#else if

#include <iostream>
using namespace std;

namespace base1{
	class A;
}
namespace base2{
	class A{
		public:
			void show(){
				cout<<"yes"<<endl;
			}
	};
}
int main(){
	////类名相同 和 名字空间不同 不能匹配 （类名 和 名字空间只要一个不相同 就不匹配） 
	base1::A *a(new base2::A);
	a->show();
	return 0;
}
#endif 

/*****************************************************************************************************/

