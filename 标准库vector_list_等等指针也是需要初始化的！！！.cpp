#include <iostream>
#include <list>
#include <Vector>

using namespace std;

class B{
public:
	B(){ name = "���"; }
	string name;
};

class A{
public:
	vector<B> * BVector;//ָ��û�г�ʼ���ռ���޷�ʹ�õ� 
}; 


int main(){
	
	A a;
	B b1;
	B b2;
#if 1
	a.BVector = new vector<B>;
#endif
	a.BVector->push_back(b1);
	a.BVector->push_back(b2);
	
	cout<< a.BVector->at(0).name;
	
	return 0;
} 
