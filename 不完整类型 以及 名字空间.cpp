/*****************************************************************************************************/

#if 0
#include <iostream>
using namespace std;

namespace base{
	class A;
}

int main(){
	//���ֿռ���Ķ��������������������ܷ��� 
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
	//���� �� ���ֿռ��� ��Ҫ��ͬ����ƥ�� 
	
	//���ָ�ֵ��ʽ������ 
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
	////������ͬ �� ���ֿռ䲻ͬ ����ƥ�� ������ �� ���ֿռ�ֻҪһ������ͬ �Ͳ�ƥ�䣩 
	base1::A *a(new base2::A);
	a->show();
	return 0;
}
#endif 

/*****************************************************************************************************/

