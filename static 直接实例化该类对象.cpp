#include <iostream>
using namespace std;

class Demo
{
public:
	Demo(){
		p = nullptr;
		cout << "构造 " << endl;	
	}
	~Demo(){
		cout << "析构 " << endl; 
	}
	
//类中的 static 的函数直接实例化一个 该类对象出来 
static Demo& getDemo(){
	Demo *a = new Demo;
	cout<<"-----"<<__LINE__<<endl;
	return *a; 
}

private:
    int *p;
};

int main()
{
	
//	Demo b = Demo::getDemo(); //必须要有 指针或变量接管new出来的空间，程序结束时才会被显示销毁 
	Demo::getDemo();	//为什么只有构造，没有析构 因为 getDemo 中的局部变量 a 被销毁了 
	cout<<"-----"<<__LINE__<<endl;
	 
    return 0;
}
