#include <stdio.h>
#include <iostream>
#include <Vector>
#include <windows.h>
using namespace std;

class A{
	
public:
#if 1
	A(int a){
		cout<<"A类无参构造"<<endl;
		cout<<arr.size()<<endl;
	} 
#endif  
	A(A * parent = nullptr){
		cout<<"-------构建对象树-------"<<endl;
		if(parent != nullptr){
			Sleep(300);
			//创建对象数列表 
			parent->arr.push_back(this);
		}
	}	

#if 1
	~A(){
		vector<A*>::iterator iter;
		for(iter=arr.begin(); iter!=arr.end(); iter++)
		{
			cout<<"-------析构对象树-------";
		}
	}
	vector <A*> arr;
#else
	~A(){	
		for(int i=0; i<10; i++)
		{
			cout<<"-------析构对象树-------";
		}
	}
	A *arr[10];
#endif
};

class B:public A{
public:
	B(A * parent = nullptr):A(parent){
		cout<<"B类构造"<<endl;
	}
};

class C: public B{
public:
	C(A *parent = nullptr):B(parent){
		cout<<"C类构造"<<endl;
	}
	static C* fun(A *parent){
		C *c = new C(parent);
	}
	
	void c_show(){
		cout<<" c show "<<endl;
	}
};

int main(){
	A a;
	
//	B b(&a);
	
	C *c1 = C::fun(&a);
	c1->c_show();

	return 0;
}

