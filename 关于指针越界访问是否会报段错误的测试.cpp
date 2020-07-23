#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int *pa = &a;
	cout <<"&pa = "<< &pa << endl;	//pa 自身的栈区地址 
	cout <<"pa = "<< pa << endl;	//pa 指向的栈区地址 
	cout<<"pa + 1  = "<<(pa+1)<<endl;
	*(pa + 1) = 25;	//栈区的越界赋值 
	
	
	int *b = new int;
	cout <<"&b = "<< &b << endl;	//b 自身的栈区地址 
	cout <<"b = "<< b << endl;		//b 指向的 堆区 地址
	cout<<"b + 1  = "<<(b+1)<<endl;
	*(b + 1) = 30; 	//堆区的越界赋值 
	
	
	int *w;
	cout<<"&w = "<<&w<<endl;
	cout<<"w = "<<w<<endl;
	cout<<"w + 1 = "<<(w+1)<<endl;
//	*w = 40;	//*w 不能赋值是因为，w指向了内核区 
//	*(w+1) = 50;	// *(w+1) 不能赋值是因为，w + 1 指向了内核区 
	

#if 0 
	int *m;  
	// m 原本指向 0x40e995 
	cout<<"&m = "<<&m<<endl;
	cout<<"m = "<<m<<endl;
	cout<<"m + 1 = "<<(m+1)<<endl;
	*(m + 1) = 60;	//m 原本指向 0x40e995 ,这个区不知道是什么区，所以不能确定是否会段错误 
#else
	int *m;  
	m = (int *)0x6ffe0c;	// m 原本指向 0x40e995 
	cout<<"&m = "<<&m<<endl;
	cout<<"m = "<<m<<endl;
	cout<<"m + 1 = "<<(m+1)<<endl;
	*(m + 1) = 60;	//由于把 m 的指向改为了栈区， 所以又可以栈区的越界访问了 
#endif 
	
    return 0;
}
