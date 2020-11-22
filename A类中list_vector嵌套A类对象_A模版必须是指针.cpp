#include <iostream>
#include <list>
#include <Vector>
using namespace std;


#if 0
//类嵌套类，结论一定是用指针
class Base {
	public:
		Base() {
			name = "Base 你好";

		}

		Base *b;//必须是指针

		string name;
};

int main() {

	Base *b = new Base;
	cout << b->name << endl;

	b->b = b;
	cout << b->b->name <<endl;
	cout << b->b->b->b->b->b->b->b->b->name<<endl;
	return 0;
}
#endif

// list<必须是指针>  vector<必须是指针> , 否则无上限拷贝构造
#if 0
class A {

	public:
		A() {
			name = "a 的 你好";
		}
		list<A*> AList;//必须是指针

//	list<A> AList;//错误，因为不是指针
		string name;
};


int main() {

	A *a = new A;
	a->AList.push_back(a);

	cout << a->name << endl;
	cout << a->AList.back()->name << endl;
	cout << a->AList.back()->AList.back()->name;

//	A a;
//	a.AList.push_back(a);
//
//	cout << a.name << endl;
//	cout << a.AList.back().name << endl;
//	cout << a.AList.back().AList.back().name;

	return 0;
}
#endif


#if 1
class A {

	public:
		A() {
			name = "a 的 你好";
		}
		vector<A*> AVector;//先初始化 list ,最后添加时初始化 B
		string name;
};


int main() {

	A *a = new A;
	a->AVector.push_back(a);

	cout << a->name << endl;
	cout << a->AVector.at(0)->name<< endl;
	cout << a->AVector.at(0)->AVector.at(0)->name;

	return 0;
}
#endif
