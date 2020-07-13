#include <iostream>   
#include <list>  
#include <typeinfo> 

using namespace std;   
typedef list<int> INTLIST;   

//从前向后显示 list 队列的全部元素
void put_list(list<int> list, char * name){
//	list<int>::iterator plist;//！！！！！！！！！！！！！！！！！！为什么这样定义不行 !!!!!!!
	INTLIST::iterator plist;		 
	cout<< "The contents of " << name << ":";
	for(plist = list.begin(); plist != list.end(); plist++)
	{
		cout << *plist << " "; 
	}
	cout<<endl;
}

// 测试 list 容器的功能 
int main(){
	// list 1 对象初始为空
	
	list<int> list1;
	// list 2 对象最初有 10 个值为 6 的元素
	list<long> list2(10, 6);
	// list 3 对象最初有 5 个值为 6 的元素
	list<int> list3(list2.begin(), --list2.end());

	//定义一个名为 i 的双向迭代器 
	list<int>::iterator i;
	// 从前向后显示各 list 对象的元素

	cout<<"typeid(list2.begin())";
	cout<<typeid(list2.begin()).name();
	cout<<endl<<endl;;
	
	cout<<cout<<"typeid(list2.front())";
	cout<<typeid(list2.front()).name();
	cout<<endl;
	
	return 0;
}
