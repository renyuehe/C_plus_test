#include <iostream>
using namespace std;


int main()
{
#if 1
	int a = 123;
	auto f = [&]()mutable { cout << ++a << endl; }; // �ᱨ��
	f(); // �����124
	cout << a << endl; // �����124
	f(); // �����125
#else
	int a = 123;
	auto f = [=]()mutable { cout << ++a << endl; }; // �ᱨ��
	f(); // �����124
	cout << a << endl; // �����124
	f(); // �����125
#endif 
    return 0;
}
