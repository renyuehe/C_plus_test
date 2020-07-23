#include<iostream>
//#include<iomanip>
using namespace std;

template <class T>
class Array
{
	T *set;
	int n;
public:
	Array(T *data,int i){set=data;n=i;}
	~Array(){}
	void display();
	int seek(T key); // 查找指定的元bai素
	
	void show(){
		int i;
		for(i=0; i<n; i++){
			cout<<set[i];
		}
	}
};

//查找 
/* 	 
*	为什么模版类 类外定义函数这么麻烦： 
*	首先模版类的类外定义函数，必须也是模版函数 
* 	
*	又可能因为：常规函数可以直接就内存中实现好了，而模版类的模版函数不能直接实现，需要用  函数名<T>  来表示告诉编译器，运行时编译	
*/ 
 
template <class T>
int Array<T>::seek(T key)
{
	int i;
	for(i=0;i<n;i++)
		if(set[i]==key)
		return i;
	return -1;
}
//遍历 
template <class T>
void Array<T>::display(){
	int i;
	for(i=0; i<n; i++){
		cout<<set[i];
	}
}

int main()
{
	int a[4] = {1,2,3,4};
	Array <int> *arr = new Array<int>(a,4);
	arr->show();
	arr->display();
	return 0;
}
