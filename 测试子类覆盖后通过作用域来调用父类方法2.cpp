#include <iostream>
using namespace std;
 
class A{
public: 
	virtual void set(){
		cout<<"���� ����"<<endl;
	}
};
 
class B: public A{
public:
#if 1
	void set(){
		cout<<"���� ���Ǹ��෽��"<<endl;	
	}
	
	void set2(){
		A::set();
	}
#endif

};
 
int main(){

//	A::set();	//�������Ǵ���ģ��෽����Ҫֱ���ã�������static 

	B b;
#if 1
	b.set();
	b.set2();
#endif
	b.A::set();
 	return 0;
}
