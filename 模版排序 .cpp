#include<iostream>
#include<iomanip>
using namespace std;

template <class T>
class Array
{
	T *set;
	int n;
public:
	Array(T *data,int i){set=data;n=i;}
	~Array(){}
	void sort(); // ����
	int seek(T key); // ����ָ����Ԫbai��
	T sum(); // ���
	void disp(); // ��ʾ���е�Ԫ��
};

//���� 
template<class T>
void Array<T>::sort()
{
	int i,j;
	T temp;
	for(i=1;i<n;i++)
	{
		for(j=n-1;j>=i;j--)
		{
			if(set[j-1]>set[j])
			{
				temp=set[j-1]; 
				set[j-1]=set[j]; 
				set[j]=temp;
			}
		} 
//		Array<T>::disp();	
		disp();	
	}
		
		
		
}

//���� 
template <class T>
int Array<T>::seek(T key)
{
	int i;
	for(i=0;i<n;i++)
		if(set[i]==key)
		return i;
	return -1;
}

//��� 
template<class T>
T Array<T>::sum()
{
	T s=0;int i;
	for(i=0;i<n;i++)
	{
		s+=set[i];
	}
		
	return s;
}

//���� ��ʾ 
template<class T>
void Array<T>::disp()
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<set[i];
	}
	cout<<endl;
		
}

int main()
{
	int a[] = {2,4,1,7,5,3,8,9,0,6};
	Array<int> *arr = new Array<int>(a, 10);
	arr->disp();
	cout<<"--------------------------"<<endl;
	
	arr->sort();
	arr->disp();
	cout<<"--------------------------"<<endl;
	
	cout<<"sum = "<<arr->sum()<<endl;
	cout<<"seek(5) = "<<arr->seek(5)<<endl;
	return 0;
}
