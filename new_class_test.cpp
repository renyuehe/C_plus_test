#include <iostream>
using namespace std;

class A{
public:
	void show(){
		cout<<x<<endl;
	}
	int x;
};

int main(){

	int a = 10;
	int *p = &a;
	cout<<"*(p+100) = "<<*(p+100)<<endl;
	*(p+1) = 20;		//ջ��Ҳ�ǿ���Խ�縳ֵ�� 
	cout<<"*(p+1) = "<<*(p+1)<<endl; //ջ��Ҳ�ǿ���Խ���ȡ 
//	int * bunch = new int;
//	int * bunch = new int[3];
	A * bunch = new A;
//	A * bunch = new A[3];
	
//	*bunch-> 10;
//	*(bunch+1) = 20;
//	bunch[2] = 40;
//	bunch[3] = 50;
//	bunch[4] = 100;
//	bunch[5] = 200;
	
	bunch->show();
	bunch[1].show();
	bunch[2].show();
	bunch[3].show();	//���ȷ�Ƕ�����Խ����ʣ��ǿ��Ե� 
	bunch[1000].show();
	bunch->x = 10;
	bunch[1].x = 20;
	bunch[1].show();
	(bunch+2)->x = 30;	//���ȷ�Ƕ�����Խ�縳ֵ���ǿ��Ե� 
	bunch[2].show();
//	bunch[2] = 40;
//	bunch[3] = 50;
//	bunch[4] = 100;
//	bunch[5] = 200;
	
//	cout<<*bunch<<endl;
//	cout<<*(bunch+1)<<endl;
//	cout<<bunch[2]<<endl;
//	cout<<bunch[3]<<endl;
//	cout<<bunch[4]<<endl;
//	cout<<bunch[5]<<endl;
	
	return 0;
}
