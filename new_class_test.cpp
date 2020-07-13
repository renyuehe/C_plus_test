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
	*(p+1) = 20;		//栈区也是可以越界赋值的 
	cout<<"*(p+1) = "<<*(p+1)<<endl; //栈区也是可以越界读取 
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
	bunch[3].show();	//这的确是堆区的越界访问，是可以的 
	bunch[1000].show();
	bunch->x = 10;
	bunch[1].x = 20;
	bunch[1].show();
	(bunch+2)->x = 30;	//这的确是堆区的越界赋值，是可以的 
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
