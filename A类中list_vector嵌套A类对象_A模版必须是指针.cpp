#include <iostream>
#include <list>
#include <Vector>
using namespace std;


#if 0
//��Ƕ���࣬����һ������ָ��
class Base {
	public:
		Base() {
			name = "Base ���";

		}

		Base *b;//������ָ��

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

// list<������ָ��>  vector<������ָ��> , ���������޿�������
#if 0
class A {

	public:
		A() {
			name = "a �� ���";
		}
		list<A*> AList;//������ָ��

//	list<A> AList;//������Ϊ����ָ��
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
			name = "a �� ���";
		}
		vector<A*> AVector;//�ȳ�ʼ�� list ,������ʱ��ʼ�� B
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
