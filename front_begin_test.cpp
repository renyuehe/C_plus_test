#include <iostream>   
#include <list>  
#include <typeinfo> 

using namespace std;   
typedef list<int> INTLIST;   

//��ǰ�����ʾ list ���е�ȫ��Ԫ��
void put_list(list<int> list, char * name){
//	list<int>::iterator plist;//������������������������������������Ϊʲô�������岻�� !!!!!!!
	INTLIST::iterator plist;		 
	cout<< "The contents of " << name << ":";
	for(plist = list.begin(); plist != list.end(); plist++)
	{
		cout << *plist << " "; 
	}
	cout<<endl;
}

// ���� list �����Ĺ��� 
int main(){
	// list 1 �����ʼΪ��
	
	list<int> list1;
	// list 2 ��������� 10 ��ֵΪ 6 ��Ԫ��
	list<long> list2(10, 6);
	// list 3 ��������� 5 ��ֵΪ 6 ��Ԫ��
	list<int> list3(list2.begin(), --list2.end());

	//����һ����Ϊ i ��˫������� 
	list<int>::iterator i;
	// ��ǰ�����ʾ�� list �����Ԫ��

	cout<<"typeid(list2.begin())";
	cout<<typeid(list2.begin()).name();
	cout<<endl<<endl;;
	
	cout<<cout<<"typeid(list2.front())";
	cout<<typeid(list2.front()).name();
	cout<<endl;
	
	return 0;
}
