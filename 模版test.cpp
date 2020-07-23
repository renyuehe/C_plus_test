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
	int seek(T key); // ����ָ����Ԫbai��
	
	void show(){
		int i;
		for(i=0; i<n; i++){
			cout<<set[i];
		}
	}
};

//���� 
/* 	 
*	Ϊʲôģ���� ���ⶨ�庯����ô�鷳�� 
*	����ģ��������ⶨ�庯��������Ҳ��ģ�溯�� 
* 	
*	�ֿ�����Ϊ�����溯������ֱ�Ӿ��ڴ���ʵ�ֺ��ˣ���ģ�����ģ�溯������ֱ��ʵ�֣���Ҫ��  ������<T>  ����ʾ���߱�����������ʱ����	
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
//���� 
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
