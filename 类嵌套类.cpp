#include <iostream>
using namespace std;

//���ۣ� ��Ƕ���࣬һ������ָ�� 
 
#if 0
//��Ƕ���࣬�������ָ�룬�򱨴� [Error] has incomplete type 'Base'
class Base{
	public:
		Base(){ name = "Base ���";
			
		}
		
		Base b;
		
		string name;
};

int main(){
	
	return 0;
}
#endif 

#if 1
//��Ƕ����  ָ�����  �� �� �� �� �� �� �� �� �� �� �� 
class Base{
	public:
		Base(){ name = "Base ���";
			
		}
		
		Base *b;
		
		string name;
};

int main(){
	
	Base *b = new Base;
	cout << b->name << endl;
	
	b->b = b;
	cout << b->b->name <<endl;
	cout << b->b->b->b->b->b->b->b->b->name<<endl;
	return 0;
}
#endif 


