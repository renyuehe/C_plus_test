#include <iostream>
using namespace std;


int main()
{
#if 0 
	size_t v1=42;
    auto f=[v1] () {return v1; };
    cout<<&f<<endl;
    cout<<f()<<endl;
#endif 

#if 0
	size_t v1=42;
	//v1 Ĭ���ǲ����ܸĵģ� ������仰�ǲ������ģ�ֻ�м���mutable �ؼ��ֲſ��� 
    auto f=[v1] () {return ++v1; };
    cout<<&f<<endl;
    cout<<f()<<endl;
#endif

#if 1
	//���� mutable ֮�� v1 �Ϳ��� ++ �� 
	size_t v1=42;
    auto f=[v1] () mutable { return ++v1; };
    cout<<&f<<endl;
    cout<<f()<<endl;
#endif

    return 0;
}
