#include <iostream>
using namespace std;


int main()
{
#if 1
	int a = 123;
	auto f = [&]()mutable { cout << ++a << endl; }; // 会报错
	f(); // 输出：124
	cout << a << endl; // 输出：124
	f(); // 输出：125
#else
	int a = 123;
	auto f = [=]()mutable { cout << ++a << endl; }; // 会报错
	f(); // 输出：124
	cout << a << endl; // 输出：124
	f(); // 输出：125
#endif 
    return 0;
}
