/*
	�����֣� 
*/
#include <iostream>   
#include <list>   

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
	list<int> list2(10, 6);
	// list 3 ��������� 5 ��ֵΪ 6 ��Ԫ��
	list<int> list3(list2.begin(), --list2.end());
	
	//����һ����Ϊ i ��˫������� 
	list<int>::iterator i;
	// ��ǰ�����ʾ�� list �����Ԫ��
	put_list(list1, "list1");
	put_list(list2, "list2"); 
	put_list(list3, "list3");
	
	//��list1���к����������Ԫ��
	list1.push_back(2);
	list1.push_back(4); 
	put_list(list1,"list1");
	
	//�� list1 ����ǰ�������������
	list1.push_front(5);
	list1.push_front(7);
	put_list(list1, "list1");
	
	//�� list1 �����м�������� 
	list1.insert(++list1.begin(),3);	//����һ �� 3 
	put_list(list1, "list1");
	list1.insert(++list1.begin(),3,9);	//���� 3 �� 9  
	put_list(list1, "list1");
	
	//���������ຯ��
	cout<<"list1.front() ="<<list1.front()<<endl; 
	cout<<"list1.back() ="<<list1.back()<<endl; 
	
	//�� list1 ���е�ǰ�����ȥһ��Ԫ��
	list1.pop_front();
	list1.pop_back();
	put_list(list1, "list1");
	
	//��� list1 �е� ������2��Ԫ��,	���⣺��β���++ -- ָ��һ��λ�ò����� 
	list1.erase(--list1.end()); 
	put_list(list1, "list1");
	
	// lsit2 ��ֵ 8�� 1 
	list2.assign(8,1);
	put_list(list2, "list2");
	
	// ��ʾ����״̬��Ϣ
	cout<<"list1.max_size()"<<list1.max_size()<<endl;
	cout<<"list1.size()"<<list1.size()<<endl;
	cout<<"list1.empty()"<<list1.empty()<<endl; 
	
	//�� list1 ��������
	list1.sort();
	put_list(list1, "list1");
	
	//��ϴ���
	list1.splice(++list1.begin(), list3);
	put_list(list1, "list1");
	put_list(list3, "lsit3"); 
	return 0;
}
