#include <iostream>
using namespace std;

class Demo
{
public:
	Demo(){
		p = nullptr;
		cout << "���� " << endl;	
	}
	~Demo(){
		cout << "���� " << endl; 
	}
	
//���е� static �ĺ���ֱ��ʵ����һ�� ���������� 
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
	
//	Demo b = Demo::getDemo(); //����Ҫ�� ָ�������ӹ�new�����Ŀռ䣬�������ʱ�Żᱻ��ʾ���� 
	Demo::getDemo();	//Ϊʲôֻ�й��죬û������ ��Ϊ getDemo �еľֲ����� a �������� 
	cout<<"-----"<<__LINE__<<endl;
	 
    return 0;
}
