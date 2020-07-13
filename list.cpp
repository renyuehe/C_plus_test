/*
	核心字： 
*/
#include <iostream>   
#include <list>   

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
	list<int> list2(10, 6);
	// list 3 对象最初有 5 个值为 6 的元素
	list<int> list3(list2.begin(), --list2.end());
	
	//定义一个名为 i 的双向迭代器 
	list<int>::iterator i;
	// 从前向后显示各 list 对象的元素
	put_list(list1, "list1");
	put_list(list2, "list2"); 
	put_list(list3, "list3");
	
	//从list1序列后面添加两个元素
	list1.push_back(2);
	list1.push_back(4); 
	put_list(list1,"list1");
	
	//在 list1 序列前面添加两个数据
	list1.push_front(5);
	list1.push_front(7);
	put_list(list1, "list1");
	
	//在 list1 序列中间插入数据 
	list1.insert(++list1.begin(),3);	//插入一 个 3 
	put_list(list1, "list1");
	list1.insert(++list1.begin(),3,9);	//插入 3 个 9  
	put_list(list1, "list1");
	
	//测试引用类函数
	cout<<"list1.front() ="<<list1.front()<<endl; 
	cout<<"list1.back() ="<<list1.back()<<endl; 
	
	//从 list1 序列的前后各移去一个元素
	list1.pop_front();
	list1.pop_back();
	put_list(list1, "list1");
	
	//清除 list1 中的 倒数第2个元素,	问题：如何不用++ -- 指定一个位置操作呢 
	list1.erase(--list1.end()); 
	put_list(list1, "list1");
	
	// lsit2 赋值 8个 1 
	list2.assign(8,1);
	put_list(list2, "list2");
	
	// 显示序列状态信息
	cout<<"list1.max_size()"<<list1.max_size()<<endl;
	cout<<"list1.size()"<<list1.size()<<endl;
	cout<<"list1.empty()"<<list1.empty()<<endl; 
	
	//对 list1 容器排序
	list1.sort();
	put_list(list1, "list1");
	
	//结合处理
	list1.splice(++list1.begin(), list3);
	put_list(list1, "list1");
	put_list(list3, "lsit3"); 
	return 0;
}
