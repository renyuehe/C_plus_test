#include <iostream>
#include <memory>
using namespace std;

int main(){
	
	auto a = make_shared<int>(5);
	auto b = a;
	a = make_shared<int>(6);
	cout << *b << endl;
	
	//�鿴�������� ���������� ������ָ�� 
	//cout << typeid(b).name() << endl;
	
#if 0
	#��Ӧ��python���� 
	a = 5
	b = a
	a = 6
	print(b)
#endif

	return 0;
}


