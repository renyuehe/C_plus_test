#include <stdio.h>
#include <iostream>
#include <Vector>
#include <windows.h>
using namespace std;

class A{
	
public:
#if 1
	A(int a){
		cout<<"A类整形（代替无参）构造"<<endl;
		cout<<arr.size()<<endl;
	} 
#endif  
	A(A * parent = nullptr){
		cout<<"-------A中构建对象数-------"<<endl;
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

class C:public B{
public:
	C(A * parent = nullptr):B(parent){
		cout<<"C类构造"<<endl;
	}
};

int main(){
//	A a;
	A a(10);
	
#if 0 
	B b(&a);
	C c(&b); 
#else
	C c(&a);
#endif 

	return 0;
}
