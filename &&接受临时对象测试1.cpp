#include <iostream>
using namespace std; 

class A{
public:
	string name;

	void show(){
		cout<<name<<endl;
	}
};

A getACls(){
	A a;
	a.name = "temp A Cls";
	return a;
}

int main(void)
{
	A a;

	A *b = &a;
	b->name = "b nihao";
	b->show();

	A &c = a;
	c.name = "c nihao";
	c.show();

	A &&d = getACls();	//移动构造，用来获取临时对象 
	d.show();

    return 0;
}
