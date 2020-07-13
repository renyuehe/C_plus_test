/*
new  和  delete  测试
*/ 

#include <iostream>
using namespace std;

class A{
public:
	~A(){
		cout<<"被析构"<<endl; 
	}
	
	void setCapacity(int n){
		this->_capacity = n;
	}
	void showCapacity(){
		cout<<"capacity is :"<<_capacity<<endl;
	}
private:
	int _capacity;
};

int main(){
	
	A *a = new A;
	A *b = new A [10];
	
	b[0].setCapacity(11);	
	b[0].showCapacity();
	b[3].setCapacity(19);
	b[3].showCapacity();
	
	b->setCapacity(111);
	b->showCapacity();
	(b+1)->setCapacity(112);
	(b+1)->showCapacity();
	(b+16)->setCapacity(116);	//虽然没报错，但是数组越界了 
	(b+16)->showCapacity();		//虽然没报错，但是越界了 
	
	
	delete a;
//	delete b;	//如果创建时候是创建的 类对象数组形式，析构时也要用 [] ，否则报错 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	delete [] b;

	
	return 0;
}
